#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve(vector<string> &s, int r, int c, string cur, string &ans, vector<vector<bool>> &visited) {
    // avoid revisiting the same cell in a case
    if (r < 0 || r >= 3 || c < 0 || c >= 3 || visited[r][c]) return;

    cur += s[r][c];
    if (cur.size() == 3) {
        ans = min(ans, cur);
        return;
    }

    visited[r][c] = 1;

    solve(s, r + 1, c, cur, ans, visited);
    solve(s, r, c + 1, cur, ans, visited);
    solve(s, r - 1, c, cur, ans, visited);
    solve(s, r, c - 1, cur, ans, visited);
    solve(s, r + 1, c + 1, cur, ans, visited);
    solve(s, r - 1, c - 1, cur, ans, visited);
    solve(s, r + 1, c - 1, cur, ans, visited);
    solve(s, r - 1, c + 1, cur, ans, visited);

    visited[r][c] = 0; // Unmark the cell after exploring its possibilities
}

int main() {
    fastio;
    vector<string> s(3);
    for (int i = 0; i < 3; i++) cin >> s[i];
    
    string ans = "ZZZ";
    vector<vector<bool>> visited(3, vector<bool>(3, 0));

    // the string may begin from any starting point
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            solve(s, i, j, "", ans, visited);
        }
    }

    cout << ans;
    return 0;
}