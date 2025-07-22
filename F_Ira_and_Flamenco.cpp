#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

ll fastmmi(ll a, ll mod) {
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
ll MOD=1e9+7;
    int tt;cin>>tt;
    while(tt--){
       int n,m;cin>>n>>m;
       map<ll,ll> mp;
       for(int i=0;i<n;i++){
        ll x;cin>>x;
        mp[x]++;
       }
       vector<ll> b,c;
       for(auto &[val,cnt]:mp){
        b.push_back(val);
        c.push_back(cnt);
       }
    //    for(int i=0;i<b.size();i++){
    //     cout<<b[i]<<" "<<c[i]<<"\n";
    //    }
       vector<ll> pref(c.size(),1ll);
       pref[0]=c[0];
       for(int i=1;i<c.size();i++){
        pref[i]=(pref[i-1]*c[i])%MOD;
       }
    //    for(auto e:pref) cout<<e<<" ";
       ll ans=0ll;
       int k=b.size();
       for(int i=0;i<k-m+1;i++){
        if(b[i+m-1]==(b[i]+m-1)){
            ans+=(pref[i+m-1]*(i>0?fastmmi(pref[i-1],MOD):1ll))%MOD;
            ans%=MOD;
        }
       }
       cout<<ans<<"\n";
    }
    return 0;
}