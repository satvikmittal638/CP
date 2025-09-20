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
       ll n,m,q;cin>>n>>m>>q;
       vector<ll> a(n),b(m);
       for(ll i=0;i<n;i++) cin>>a[i];
       for(ll i=0;i<m;i++) cin>>b[i];
       sort(all(a));sort(all(b));
       reverse(all(a));reverse(all(b));//descending
       vector<pair<ll,ll>> cnt(n+m+1); // cnt[z] denotes solution pair {x',y'}
       ll i=0,j=0,froma=0,fromb=0;
       // merge both arrays
       while(i<n && j<m){
           if(a[i]>b[j]){
               i++;
               froma++;
            }
            else{
                j++;
                fromb++; 
            }   
            cnt[froma+fromb]={froma,fromb};
       }
       while(i<n){
        i++;
        froma++;
        cnt[froma+fromb]={froma,fromb};
       }
       while(j<m){
        j++;
        fromb++;
        cnt[froma+fromb]={froma,fromb};
       }
    //    for(auto [x,y]:cnt) cout<<x<<" "<<y<<"\n";
       vector<ll> pa(n+1,0),pb(m+1,0);
       for(ll i=0;i<n;i++) pa[i+1]=pa[i]+a[i];
       for(ll i=0;i<m;i++) pb[i+1]=pb[i]+b[i];
       while(q--){
        ll x,y,z;cin>>x>>y>>z;
        auto [xp,yp]=cnt[z];
        ll ans=0ll;
        if(xp>x){
            ans=pa[x]+pb[yp+(xp-x)];
        }
        else if(yp>y){
            ans=pa[xp+(yp-y)]+pb[y];
        }
        else{
            ans=pa[xp]+pb[yp];
        }
        cout<<ans<<"\n";
       }
    }
    return 0;
}