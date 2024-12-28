#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()

int main() {
    fastio;
    const int MAX = 1e5;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> x(MAX + 1), y(MAX + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int c;
            cin >> c;
            x[c].emplace_back(i);
            y[c].emplace_back(j);
        }
    }
    ll ans = 0;
    for (int c = 1; c <= MAX; c++) {
        sort(all(x[c]));
        sort(all(y[c]));
        // Calculate contribution for rows
        ll sum_x = 0;
        for (int i = 0; i < x[c].size(); i++) {
            ans += (ll)x[c][i] * i - sum_x;
            sum_x += x[c][i];
        }
        // Calculate contribution for columns
        ll sum_y = 0;
        for (int i = 0; i < y[c].size(); i++) {
            ans += (ll)y[c][i] * i - sum_y;
            sum_y += y[c][i];
        }
    }
    cout << ans << '\n';
    return 0;
}