#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll MAXN=4*1e6+5;
const ll MOD=998244353;

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

    // Precompute factorials
    vector<ll> fact(MAXN);
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    auto C = [&](ll n, ll k) {
        if(n<k) return 1ll;
        return fact[n] * fastmmi(fact[k] * fact[n - k] % MOD) % MOD;
    };
    int tt;cin>>tt;
    while(tt--){
       ll c1,c2,c3,c4;cin>>c1>>c2>>c3>>c4;
       if((c1+c2+c3+c4)==0){
        cout<<"1\n";
        continue;
       }
       if(abs(c1-c2)>1){
        cout<<0<<"\n";
        continue;
       }
       if((c1+c2)==0){
        if(c3*c4>0){
            cout<<"0\n";
        }
        else{
            cout<<"1\n";
        }
        continue;
       }

       ll ans;
       if(c1==c2){
        ans=(C(c4+c2,c4)*C(c3+c1-1,c3))%MOD+(C(c3+c1,c3)*C(c4+c2-1,c4))%MOD;
       }
       else if(c1==c2+1){
        ans=C(c1+c3-1,c3)*C(c1+c4-1,c4);
       }
       else{
        ans=C(c2+c3-1,c3)*C(c2+c4-1,c4);
       }
       ans%=MOD;
       cout<<ans<<"\n";
    }
    return 0;
}