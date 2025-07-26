#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll MOD=998244353;

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
int main()
{
fastio;
    ll n;cin>>n;
    for(ll i=1;i<n;i++){
        ll ans=(81*(n-i-1ll)*modexp(10,n-i-1))%MOD; // block neither starts at 1st index nor ends at last index
        ans+=2*10*9*modexp(10,n-i-1ll); // block either starts at 1st index or ends at last index
        ans%=MOD;
        cout<<ans<<" ";
    }
    cout<<10;// i=n
    return 0;
}