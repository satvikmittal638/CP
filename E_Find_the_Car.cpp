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
       ll n,k,q;cin>>n>>k>>q;
       vector<ll> a(k+1),b(k+1);
       for(ll i=1;i<=k;i++) cin>>a[i];
       for(ll i=1;i<=k;i++) cin>>b[i];
       while(q--){
        ll d;cin>>d;
        ll i=lower_bound(all(a),d)-a.begin();
        if(a[i]==d){
            cout<<b[i]<<" ";
        }
        else{
            ll t=b[i-1]+(d-a[i-1])*(b[i]-b[i-1])/(a[i]-a[i-1]);
            cout<<t<<" ";
        }
       }
       cout<<"\n";
    }
    return 0;
}