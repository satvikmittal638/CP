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
       ll n;cin>>n;
       ll px,py,qx,qy;cin>>px>>py>>qx>>qy;
       vector<ll> a(n);for(auto &i:a) cin>>i;
       ll total=accumulate(all(a),0ll);
       ll dx=qx-px,dy=qy-py;
       ll D=dx*dx+dy*dy;
       ll lo=max(0ll,2*(*max_element(all(a)))-total),hi=total;
       if(lo*lo<=D && D<=hi*hi){
        cout<<"Yes\n";
       }
       else{
        cout<<"No\n";
       }
    }
    return 0;
}