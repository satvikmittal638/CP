#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll MOD=1e9+7;

ll modexp(ll base, ll exp) {
    ll res = 1ll;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2ll;
    }
    return res;
}

ll fastmmi(ll a) {
    return modexp(a,MOD-2);
}

int main()
{
    fastio;
    ll n;
    string s;cin>>s;
    n=s.length();
    s=' '+s;// 1-indexed
    ll ans=0ll;
    
    // Precompute modular inverse of 81
    ll mmi81 = fastmmi(81);

    for(ll i=1;i<=n;i++){
        ll d=s[i]-'0';

        ll term_bef_count = (i * (i-1) / 2) % MOD;
        ll place_value = modexp(10, n - i);
        ll bef = (d * term_bef_count) % MOD;
        bef = (bef * place_value) % MOD;
        ans = (ans + bef) % MOD;

        ll aft = 0;
        // Computed AGP sum
        if (i < n) {
            ll N = n - i-1; 
            ll term1 = (90ll * N) % MOD;
            term1 = (term1 + 80) % MOD;
            if(term1 < 0) term1 += MOD;
            
            term1 = (term1 * modexp(10, N)) % MOD;
            term1 = (term1 + 1) % MOD;
            
            aft = (d * term1) % MOD;
            aft = (aft * mmi81) % MOD;
        }
        ans = (ans + aft) % MOD;
    }
    cout << ans;
    return 0;
}