#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

int main() {
    fastio;
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> p(n);
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            x--;  
            p[i] = x;
        }

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int u = i, len = 0;
                while (!visited[u]) {
                    visited[u] = true;
                    u = p[u];
                    len++;
                }
                ans += (len-1) / 2;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}