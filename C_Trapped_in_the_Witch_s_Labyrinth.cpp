#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Directions: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

// Function to perform DFS to detect cycles
bool dfs(int x, int y, vector<vector<int>>& visited, vector<vector<char>>& directions, int n, int m, vector<pair<int, int>>& cyclePath) {
    vector<pair<int, int>> path;
    while (x >= 0 && x < n && y >= 0 && y < m) {
        if (visited[x][y] == 1) {  // Already visited in this DFS call (cycle detected)
            cyclePath = path;
            return true;
        }
        if (visited[x][y] == 2) {  // Already processed (no cycle)
            return false;
        }
        
        visited[x][y] = 1;  // Mark as visited in this DFS call
        path.push_back({x, y});

        // Move according to the current direction
        if (directions[x][y] == 'U') {
            x -= 1;
        } else if (directions[x][y] == 'D') {
            x += 1;
        } else if (directions[x][y] == 'L') {
            y -= 1;
        } else if (directions[x][y] == 'R') {
            y += 1;
        } else {
            break;
        }
    }
    
    // No cycle detected, mark the path as processed
    for (auto& p : path) {
        visited[p.first][p.second] = 2;
    }
    return false;
}

void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<char>> grid(n, vector<char>(m));
        vector<vector<char>> directions(n, vector<char>(m, '?')); // Initialize all directions as '?'
        vector<vector<int>> visited(n, vector<int>(m, 0)); // 0 = unvisited, 1 = visiting, 2 = processed
        
        // Read grid input
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                if (grid[i][j] != '?') {
                    directions[i][j] = grid[i][j];
                }
            }
        }
        
        int trappedCells = 0;
        
        // Process each cell for cycles
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == 0) { // Unvisited cell
                    vector<pair<int, int>> cyclePath;
                    if (dfs(i, j, visited, directions, n, m, cyclePath)) {
                        trappedCells += cyclePath.size();
                    }
                }
            }
        }
        
        cout << trappedCells << endl;
    }
}

int main() {
    solve();
    return 0;
}