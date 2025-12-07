#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

map<pair<ll,ll>,ll> dp;

ll get_carries(ll n, ll l) {
    return __builtin_ctzll(~(n >> l));
}

ll solve(ll n, ll k) {
    // base case-1
    if (k == 0) return 0;
    
    // base case-2
    ll p = __builtin_popcountll(n);
    if (p == 1) return k;


    // base-case 3
    ll h = 63 - __builtin_clzll(n);
    ll l = __builtin_ctzll(n);
    ll thres = (h - l + 1) - p + 1; 
    if(k>=max(1ll,thres)) return k+p-1;
    auto key=make_pair(n,k);
    if (dp.count(key)) return dp[key];

    ll best = 0;
    
    for (ll i = 0; i <= h+1; i++) {
        ll c = get_carries(n, i);
        best = max(best, c + solve(n + (1ll << i), k - 1));
    }

    return dp[key] = best;
}

int main() {
    fastio;
    int tt;
    cin >> tt;
    while (tt--) {
        ll n, k;
        cin >> n >> k;
        dp.clear();
        cout<<solve(n,k)<<'\n';
    }
    return 0;
}