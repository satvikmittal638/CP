#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    fastio;
    int tt; cin >> tt;
    while (tt--) {
        string t; cin >> t;
        int n; cin >> n;
        vector<string> s(n);
        for (int i = 0; i < n; i++) cin >> s[i];

        int m = t.size();
        // store all itvls: {left, right, index_of_s, position_in_t}
        vector<array<int,3>> itvls; // {l, r, idx}
        vector<pair<int,int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int len = s[j].size();
                if (i+len <= m && t.substr(i, len) == s[j]) {
                    itvls.push_back({i, i+len-1, j});
                }
            }
        }

        int cur = 0, ptr = 0;
        while (cur < m) {
            int bstR = -1, bstIdx = -1, bstStart = -1;
            for (auto &seg : itvls) {
                int l = seg[0], r = seg[1], idx = seg[2];
                if (l <= cur && r >= cur && r > bstR) {
                    bstR = r;
                    bstIdx = idx;
                    bstStart = l;
                }
            }
            if (bstR == -1) { // stuck
                cout << -1 << "\n";
                goto nextcase;
            }
            ans.push_back({bstIdx+1, bstStart+1}); // +1 for 1-based
            cur = bstR+1;
        }

        cout << ans.size() << "\n";
        for (auto &p: ans) cout << p.first << " " << p.second << "\n";

        nextcase:;
    }
    return 0;
}