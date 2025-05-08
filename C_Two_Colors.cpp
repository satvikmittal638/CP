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
       vector<ll> a(m);for(auto &i:a) cin>>i;
       sort(all(a));
       ll ans=0ll;
       for(ll k=1;k<=n/2;k++){
        ll cntk=a.end()-lower_bound(all(a),k);
        ll cntn_k=a.end()-lower_bound(all(a),n-k);
        ans+=cntk*cntn_k-cntn_k;
        // cout<<k<<"  ";
        // cout<<cntk<<" "<<cntn_k<<" "<<ans<<"\n";
       }
       for(ll k=(n/2)+1;k<n;k++){
        ll cntk=a.end()-lower_bound(all(a),k);
        ll cntn_k=a.end()-lower_bound(all(a),n-k);
        ans+=cntk*cntn_k-cntk;
        // cout<<k<<"  ";
        // cout<<cntk<<" "<<cntn_k<<" "<<ans<<"\n";
       }
       cout<<ans<<"\n";
    }
    return 0;
}