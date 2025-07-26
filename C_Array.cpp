#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll MOD=1000000007;

ll fastmmi(ll a) {
    ll res = 1ll, exp = MOD - 2;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        exp /= 2;
    }
    return res;
}

int main()
{
fastio;
    ll n;cin>>n;
    vector<ll> fact(2*n);
    fact[0] = 1;
    for (int i = 1; i < 2*n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    ll ans=(fact[2*n-1] * fastmmi(fact[n] * fact[n - 1] % MOD) % MOD);
    ans=(ans*2)%MOD;
    ans=(ans-n+MOD)%MOD;
    cout<<ans;
    return 0;
}