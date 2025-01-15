#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

int main() {
    // CF submission
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    fastio;
    int ans = 0;
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<vector<int>> adj(n);
        
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--; 
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        auto hght = [&](int start) {
            vector<bool> visited(n, false); // Reset visited for each call
            queue<pair<int, int>> q; // (node, depth)
            q.push({start, 0});
            visited[start] = true;

            int maxDepth = 0;
            while (!q.empty()) {
                auto [v, depth] = q.front();
                q.pop();
                maxDepth = max(maxDepth, depth);

                for (auto u : adj[v]) {
                    if (!visited[u]) {
                        visited[u] = true;
                        q.push({u, depth + 1});
                    }
                }
            }
            return maxDepth;
        };

        int maxHt = 0;
        for (int i = 0; i < n; i++) {
            maxHt = max(maxHt, hght(i));
        }

        // cout << maxHt << " ";
        ans += maxHt;
    }
    cout << ans << endl;
    return 0;
}