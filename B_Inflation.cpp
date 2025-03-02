#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

ll rf(ll a,ll b){
    return (a+b-1)/b;
}

int main()
{
fastio;
    ll tt;cin>>tt;
    while(tt--){
       ll n,k;cin>>n>>k;
       vector<ll> p(n+1),pref(n+1);
       for(ll i=1;i<=n;i++) cin>>p[i];
       partial_sum(p.begin()+1,p.end(),pref.begin()+1);
       ll ans=0ll;
       for(ll i=2;i<=n;i++){
        ll del=rf(1ll*100*p[i],k)-(pref[i-1]+ans);
        if(del>0){
            ans+=del;
        }
       }
       cout<<ans<<"\n";
    }
    return 0;
}