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
    while(tt--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n), h(n);
        for(auto &i : a) cin >> i;
        for(auto &i : h) cin >> i;

        int ans = 0;
        ll curFruits = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {
            // Add current fruit to the window
            curFruits += a[r];

            // Check condition for height compatibility and remove excess fruits
            while (l < r && (curFruits > k || h[l] % h[l + 1] != 0)) {
                curFruits -= a[l];
                l++;
            }

            // Update maximum window size
            if (curFruits <= k) {
                ans = max(ans, r - l + 1);
            }

            // Reset window if heights break condition
            if (r < n - 1 && h[r] % h[r + 1] != 0) {
                curFruits = 0;
                l = r + 1;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}