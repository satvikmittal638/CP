/**
 * bug_game_solver.cpp
 * Compile: g++ -std=c++17 -O3 -I/opt/homebrew/include -I~/compute/include -framework OpenCL -o solver bug_game_solver.cpp
 * Run:     echo "21 31" | ./solver > best_maze.txt
 */

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

// Boost Compute
#include <boost/compute/core.hpp>
#include <boost/compute/algorithm/copy.hpp>
#include <boost/compute/container/vector.hpp>
#include <boost/compute/utility/source.hpp>

namespace compute = boost::compute;

// --- OpenCL Kernel: The Bug Simulator ---
const char source[] = BOOST_COMPUTE_STRINGIZE_SOURCE(
    __kernel void solve_mazes(__global const char* walls, 
                              __global int* scores, 
                              __global int* global_visits, 
                              int n_mazes) 
    {
        int gid = get_global_id(0);
        if(gid >= n_mazes) return;

        int map_offset = gid * 651; // 21 * 31 = 651

        // 1. Initialize Visits (Must be 0)
        for(int i=0; i<651; i++) global_visits[map_offset + i] = 0;

        int r = 1, c = 1;
        int dir = 0; // 0=Down, 1=Right, 2=Up, 3=Left
        int steps = 0;
        int max_steps = 200000; 

        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};

        while(steps < max_steps) {
            int curr = r * 31 + c;
            
            // Mark visit
            global_visits[map_offset + curr]++;
            steps++;

            // Exit Condition
            if(r == 19 && c == 29) break;

            // Scan Neighbors
            int min_v = 2147483647;
            int neighbor_vals[4];
            bool neighbor_valid[4];

            for(int i=0; i<4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                neighbor_valid[i] = false;
                neighbor_vals[i] = 2147483647;

                if(nr >= 0 && nr < 21 && nc >= 0 && nc < 31) {
                    int nidx = nr * 31 + nc;
                    // Check Wall (0 = Empty, 1 = Wall)
                    if(walls[map_offset + nidx] == 0) { 
                        int v = global_visits[map_offset + nidx];
                        neighbor_vals[i] = v;
                        neighbor_valid[i] = true;
                        if(v < min_v) min_v = v;
                    }
                }
            }

            // Move Logic
            int next_dir = -1;

            // Rule 1: Momentum (Keep current dir if it's minimal)
            if(neighbor_valid[dir] && neighbor_vals[dir] == min_v) {
                next_dir = dir;
            } 
            // Rule 2: Priority (D, R, U, L)
            else {
                for(int i=0; i<4; i++) {
                    if(neighbor_valid[i] && neighbor_vals[i] == min_v) {
                        next_dir = i;
                        break;
                    }
                }
            }

            if(next_dir != -1) {
                dir = next_dir;
                r += dr[dir];
                c += dc[dir];
            } else {
                break; // Trapped
            }
        }
        scores[gid] = steps;
    }
);

// --- CPU Helper: Generate 1 Random Maze ---
void generateMaze(std::vector<char>& maze_flat) {
    // 30% Wall Density
    for(int i=0; i<651; i++) maze_flat[i] = (rand() % 100 < 30) ? 1 : 0;

    // Force Borders
    for(int r=0; r<21; r++) {
        for(int c=0; c<31; c++) {
            if(r==0 || r==20 || c==0 || c==30) maze_flat[r*31+c] = 1;
        }
    }

    // Force Start and End Clear
    maze_flat[1*31+1] = 0;
    maze_flat[19*31+29] = 0;
    maze_flat[1*31+2] = 0; // Right of start
    maze_flat[2*31+1] = 0; // Down of start
}

int main() {
    // 1. Adhere to Input Scheme (Read dimensions)
    int R, C;
    if (std::cin >> R >> C) { 
        // We ignore R,C because the problem fixes them at 21x31
    }

    srand(time(0));
    int N = 100000; // Simulate 100,000 mazes

    // 2. Setup GPU
    compute::device device = compute::system::default_device();
    if(device.name().find("Apple") == std::string::npos) {
         try { device = compute::system::find_device("Apple"); } catch(...) {}
    }
    compute::context context(device);
    compute::command_queue queue(context, device);

    // 3. Build Kernel
    compute::program program = compute::program::create_with_source(source, context);
    program.build();
    compute::kernel kernel(program, "solve_mazes");

    // 4. Generate Random Mazes (CPU)
    std::vector<char> host_walls(N * 651);
    std::vector<int> host_scores(N);
    for(int i=0; i<N; i++) {
        std::vector<char> m(651);
        generateMaze(m);
        for(int j=0; j<651; j++) host_walls[i*651 + j] = m[j];
    }

    // 5. Run on GPU
    compute::vector<char> dev_walls(N * 651, context);
    compute::vector<int> dev_scores(N, context);
    compute::vector<int> dev_visits(N * 651, context); // Large Global Memory Buffer

    compute::copy(host_walls.begin(), host_walls.end(), dev_walls.begin(), queue);

    kernel.set_arg(0, dev_walls);
    kernel.set_arg(1, dev_scores);
    kernel.set_arg(2, dev_visits);
    kernel.set_arg(3, N);

    queue.enqueue_1d_range_kernel(kernel, 0, N, 0);
    queue.finish();

    compute::copy(dev_scores.begin(), dev_scores.end(), host_scores.begin(), queue);

    // 6. Find Best and Output
    int maxScore = -1;
    int bestIdx = -1;
    for(int i=0; i<N; i++) {
        if(host_scores[i] > maxScore) {
            maxScore = host_scores[i];
            bestIdx = i;
        }
    }

    // Output strictly in problem format
    if(bestIdx != -1) {
        // Optional: Print score to stderr so it doesn't mess up the output file
        std::cerr << "Best Score Found: " << maxScore << std::endl;
        
        for(int r=0; r<21; r++) {
            for(int c=0; c<31; c++) {
                int idx = bestIdx*651 + r*31 + c;
                if(host_walls[idx] == 1) std::cout << "#";
                else std::cout << ".";
            }
            std::cout << "\n";
        }
    }

    return 0;
}