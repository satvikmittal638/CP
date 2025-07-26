#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll mod=1e9+7;
ll fastmmi(ll a) {
    a%=mod;
    ll res = 1, exp = mod - 2;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        exp /= 2;
    }
    return res;
}

int main()
{
fastio;
    ll tt;cin>>tt;
    while(tt--){
       ll n;cin>>n;
       vector<ll> a(n),pref(n);for(auto &i:a) cin>>i;
       pref[0]=a[0];
       for(ll i=1;i<n;i++){
        pref[i]=(pref[i-1]+a[i])%mod;
       }
       ll ans=0ll;
       for(ll i=1;i<n;i++){
        ans+=(a[i]*pref[i-1])%mod;
        ans%=mod;
       }
       ans=(ans*fastmmi(n*(n-1)/2))%mod;
       cout<<ans<<"\n";
    }
    return 0;
}