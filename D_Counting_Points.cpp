#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    ll tt;cin>>tt;
    while(tt--){
       ll n,m;cin>>n>>m;
       vector<ll> X(n),R(n);for(auto &i:X) cin>>i;
        for(auto &i:R) cin>>i;
        map<ll,pair<ll,ll>> mp; // x->{maxY,minY}
        for(ll i=0;i<n;i++){
            for(ll x=X[i]-R[i];x<=X[i]+R[i];x++){
                ll a=sqrt(R[i]*R[i]-(x-X[i])*(x-X[i]));
                mp[x].first=max(mp[x].first,a);
                mp[x].second=min(mp[x].second,-a);
            }
        }
        ll ans=0ll;
        for(auto &[x,Y]:mp){
            auto [hi,lo]=Y;
            ans+=hi-lo+1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}