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
       ll n,a,b;cin>>n>>a>>b;
       vector<ll> x(n);for(auto &i:x) cin>>i;
       ll ans;
       if(b>=a){
        ans=b*x[n-1]+a*x[n-2];
       }
       else{
        ans=b*accumulate(all(x),0ll);
       }
       cout<<ans<<"\n";
    }
    return 0;
}