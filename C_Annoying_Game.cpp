#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll INF=1e18;

int main()
{
    fastio;
    int tt; cin >> tt;
    while(tt--){
       int n, k; 
       cin >> n >> k;
       vector<ll> a(n+1, 0), b(n+1, 0); 
       for(int i=1; i<=n; i++) cin >> a[i];
       for(int i=1; i<=n; i++) cin >> b[i];

       vector<ll> pref(n+1, 0);
       partial_sum(all(a), pref.begin());

       vector<ll> smax(n+2, -INF);
       for (int i = n; i >= 1; --i) {
           smax[i] = max(smax[i+1], pref[i]);
       }

       ll ans = -INF;

       if(k % 2 == 0){
           ll cur_sum = 0;
           ll max_so_far = -INF;
           for(int i=1; i<=n; i++){
               cur_sum += a[i];
               if(max_so_far < cur_sum) max_so_far = cur_sum;
               if(cur_sum < 0) cur_sum = 0;
           }
           ans = max_so_far;
       }
       else{
             ll pmin = 0;
             ans = -INF;
             for(int i=1; i<=n; i++){
                ll cur = smax[i] - pmin + b[i];
                ans = max(ans, cur);
                pmin = min(pmin, pref[i]);
            }
       }
       cout << ans << '\n';
    }
    return 0;
}