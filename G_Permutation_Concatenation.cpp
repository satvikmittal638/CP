#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll MOD=998244353;

ll modexp(ll base, ll exp) {
    ll res = 1ll;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2ll;
    }
    return res;
}

ll modFact(ll n) {
    ll ans = 1ll;
    for (ll i = 2; i <= n; i++) ans = (ans * i) % MOD;
    return ans;
}

ll fastmmi(ll a) {
    return modexp(a, MOD - 2);
}

int main() {
    fastio;
    ll n;
    cin >> n;
    
    ll ans=1ll;
    ans = modFact(n + 1);
    
    ans *= (modexp(10, n) - 1 + MOD) % MOD;  
    ans %= MOD;
    
    ans *= fastmmi(18);
    ans %= MOD;
    
    cout << ans << "\n";
    return 0;
}