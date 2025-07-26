#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll MOD=998244353;
const ll MAX=5*1e5+5;

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
    // precompute factorials
    vector<ll> fact(MAX,0ll);
    fact[0]=1;
    for(ll i=1;i<MAX;i++){
        fact[i]=(i*fact[i-1])%MOD;
    }
    int tt;cin>>tt;
    while(tt--){
       vector<ll> c(26);for(auto &i:c) cin>>i;
       ll S=accumulate(all(c),0ll),odd=(S+1)/2,even=S/2;
       vector<ll> dp(S+5,0ll);
       dp[0]=1; // 1 way for empty subset
       for(int i=0;i<26;i++){
        if(c[i]==0) continue;
        for(ll j=S;j>=0;j--){
            if(j+c[i]<=S) dp[j+c[i]]=(dp[j+c[i]]+dp[j])%MOD;
        }
       }
       ll ans=(((fact[odd]*fact[even])%MOD)*dp[odd])%MOD,den=1ll;
       for(auto e:c) den=(den*fact[e])%MOD;
       ans=(ans*fastmmi(den))%MOD;
       cout<<ans<<"\n";

    }
    return 0;
}