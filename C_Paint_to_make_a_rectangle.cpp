#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
using namespace std;
int main() {
    fastio;
    int H, W;
    cin >> H >> W;

    vector<string> grid(H);
    for (int i = 0; i < H; ++i) {
        cin >> grid[i];
    }

    int min_row = H, max_row = -1, min_col = W, max_col = -1;

    // Find the bounds of the black cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] == '#') {
                min_row = min(min_row, i);
                max_row = max(max_row, i);
                min_col = min(min_col, j);
                max_col = max(max_col, j);
            }
        }
    }

    // Check cells inside the rectangle
    for (int i = min_row; i <= max_row; ++i) {
        for (int j = min_col; j <= max_col; ++j) {
            if (grid[i][j] == '.') {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    // Check cells outside the rectangle
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i < min_row || i > max_row || j < min_col || j > max_col) {
                if (grid[i][j] == '#') {
                    cout << "No\n";
                    return 0;
                }
            }
        }
    }

    cout << "Yes\n";
    return 0;
}