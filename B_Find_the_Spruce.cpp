#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
    fastio;
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0)), maxHtOfSpruce(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            string s; cin >> s;
            s = " " + s;
            for (int j = 1; j <= m; j++) {
                if (s[j] == '*') {
                    pref[i][j]++;
                    maxHtOfSpruce[i][j] = 1;
                }
                pref[i][j] += pref[i][j - 1];
            }
        }
        ll ans = 0;
        auto maxHtPossible = [&](int i, int j) {
            int lo = maxHtOfSpruce[i][j], hi = maxHtOfSpruce[i - 1][j] + 1;
            while (lo < hi) {
                int mid = (lo + hi + 1) / 2;
                if (j - (mid - 1) >= 1 && j + (mid - 1) <= m) {
                    int cnt = pref[i][j + (mid - 1)] - pref[i][j - (mid - 1) - 1];
                    if (cnt == 2 * mid - 1) lo = mid;
                    else hi = mid - 1;
                } else hi = mid - 1;
            }
            return lo;
        };
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int maxH = maxHtPossible(i, j);
                maxHtOfSpruce[i][j] = maxH;
                ans += maxH;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}