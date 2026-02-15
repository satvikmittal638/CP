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
        ll n, m, k;
        cin >> n >> m >> k;
        
        ll left = k - 1;
        ll right = n - k;
        
        ll ans = 1; // home base
        
        // L>=R
        // try to cover all possible lengths to left
        for (ll L = 0; L <= left; L++) {
            // 2*L + R <= M + 1
            ll cost = m + 1 - 2 * L;
            if (cost < 0) break; // can't affrd this L
            
            // R can be at most cost, at most right, and at most L (since L is max)
            ll R = min({cost, right, L});
            ans = max(ans, 1 + L + R);
        }

        // R>=L
        for (ll R = 0; R <= right; R++) {
            // 2*R + L <= M + 1
            ll cost = m + 1 - 2 * R;
            if (cost < 0) break;
            
            ll L = min({cost, left, R});
            ans = max(ans, 1 + L + R);
        }

        cout << ans << "\n";
    }
    return 0;
}