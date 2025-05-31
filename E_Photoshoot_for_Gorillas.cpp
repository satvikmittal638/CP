#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       ll n,m,k,w;cin>>n>>m>>k>>w;
       vector<ll> a(w);for(auto &i:a) cin>>i;
       sort(rall(a));
       vector<ll> cnt;
       for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            ll l=min(i,n-k)-max(-1ll,i-k);
            ll b=min(j,m-k)-max(-1ll,j-k);
            cnt.push_back(l*b);
        }
       }
       sort(rall(cnt));
       ll ans=0ll;

       for(int i=0;i<w;i++){
        ans+=a[i]*cnt[i];
       }
       cout<<ans<<"\n";
    }
    return 0;
}