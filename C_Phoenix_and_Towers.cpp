#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

int main() {
    fastio;
    int tt; cin >> tt;
    while (tt--) {
        int n, m, x; cin >> n >> m >> x;
        vector<pair<int, int>> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i].first;
            h[i].second = i;
        }
        sort(all(h)); // Sort blocks by height
        vector<int> ans(n);
        priority_queue<pair<int, int>> pq;

        // Initialize the m towers with the largest blocks
        for (int i = n - m; i < n; i++) {
            ans[h[i].second] = i - (n - m); // Assign tower index
            pq.push({-h[i].first, i - (n - m)}); // Push into min-heap
        }

        // Distribute remaining blocks
        for (int i = n - m - 1; i >= 0; i--) {
            auto [ht, idx] = pq.top();
            pq.pop();
            ans[h[i].second] = idx; // Assign block to smallest tower
            ht += -h[i].first; // Update tower height
            pq.push({ht, idx}); // Push updated tower back
        }

        // Calculate final tower heights
        vector<int> towerHeights(m, 0);
        while (!pq.empty()) {
            auto [ht, idx] = pq.top();
            pq.pop();
            towerHeights[idx] = -ht; // Convert back to positive height
        }

        int mn = *min_element(all(towerHeights));
        int mx = *max_element(all(towerHeights));

        if (abs(mx - mn) <= x) {
            cout << "YES\n";
            for (auto e : ans) cout << e + 1 << " ";
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}