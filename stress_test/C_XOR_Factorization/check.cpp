#include <iostream>
#include <vector>
#include <numeric>
#include <fstream>
#include <string>

using namespace std;

// Helper to read K integers from a file
vector<long long> read_solution(string filename, int k, long long n) {
    ifstream fin(filename);
    if (!fin) {
        cerr << "Error: Could not open " << filename << endl;
        exit(1);
    }
    vector<long long> res;
    long long val;
    for (int i = 0; i < k; i++) {
        if (!(fin >> val)) {
            cerr << "FAIL in " << filename << ": Not enough integers (expected " << k << ")" << endl;
            exit(1);
        }
        res.push_back(val);
    }
    return res;
}

int main(int argc, char* argv[]) {
    // Usage: ./check input.txt my_out.txt sol_out.txt
    if (argc < 4) {
        cerr << "Usage: ./check <input> <my_output> <sol_output>" << endl;
        return 1;
    }

    ifstream fin(argv[1]); // Input file
    int t; 
    if (!(fin >> t)) return 0; // Empty input

    while (t--) {
        long long n, k;
        fin >> n >> k;

        // 1. Read and Validate MY Output
        vector<long long> my_a = read_solution(argv[2], k, n);
        long long my_xor = 0;
        long long my_sum = 0;
        for (long long x : my_a) {
            if (x < 0 || x > n) {
                cout << "FAIL: My output has invalid number " << x << " (must be <= " << n << ")" << endl;
                return 1;
            }
            my_xor ^= x;
            my_sum += x;
        }
        if (my_xor != n) {
            cout << "FAIL: My XOR sum is " << my_xor << ", expected " << n << endl;
            return 1;
        }

        // 2. Read Reference Output (Sol) to compare Sums
        vector<long long> sol_a = read_solution(argv[3], k, n);
        long long sol_sum = 0;
        for (long long x : sol_a) sol_sum += x;

        // 3. Compare Optimality
        if (my_sum < sol_sum) {
            cout << "FAIL: Suboptimal sum. My sum: " << my_sum << ", Optimal sum: " << sol_sum << endl;
            cout << "Input: n=" << n << ", k=" << k << endl;
            cout << "My Output: ";
            for(auto x : my_a) cout << x << " ";
            cout << "\nSol Output: ";
            for(auto x : sol_a) cout << x << " ";
            cout << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}