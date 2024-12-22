#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

int main() {
    fastio;
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<vector<char>> grid(3, vector<char>(n + 1));  // grid indexing starts from 1 to n
        vector<vector<bool>> visited(3, vector<bool>(n + 1, false));  // visited array
        for (int i = 1; i <= n; i++) cin >> grid[1][i];  // Read the first row
        for (int i = 1; i <= n; i++) cin >> grid[2][i];  // Read the second row

        bool reached = false;
        vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};  // Directions
        queue<int> qx, qy;  // BFS queues for x and y coordinates
        qx.push(1); qy.push(1);  // Start from (1,1)
        visited[1][1] = true;

        while (!qx.empty()) {
            int x = qx.front(), y = qy.front();
            qx.pop(); qy.pop();

            if (x == n && y == 2) {
                reached = true;
                break;
            }

            // We can move in any direction from even cell (x + y) % 2 == 0
            if ((x + y) % 2 == 0) {
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (1 <= nx && nx <= n && 1 <= ny && ny <= 2 && !visited[ny][nx]) {
                        visited[ny][nx] = true;
                        qx.push(nx);
                        qy.push(ny);
                    }
                }
            }
            // From odd cells, we move based on the direction specified by the arrow
            else {
                int nx, ny = y;  // Keep the y-coordinate constant
                if (grid[y][x] == '<') {
                    nx = x - 1;  // Move left (up the grid)
                } else if (grid[y][x] == '>') {
                    nx = x + 1;  // Move right (down the grid)
                }

                if (1 <= nx && nx <= n && 1 <= ny && ny <= 2 && !visited[ny][nx]) {
                    visited[ny][nx] = true;
                    qx.push(nx);
                    qy.push(ny);
                }
            }
        }

        cout << (reached ? "YES" : "NO") << "\n";
    }
    return 0;
}