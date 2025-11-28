#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
// gets the position of a given no. p
ll getPos(ll p, ll x, ll y) {
    ll pos = p;
    for (int i = 0; i < x; i++) {
        pos=pos-(pos/y); 
        if (pos <= 0) return -1;    
    }
    return pos;
}
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       ll x,y,k;cin>>x>>y>>k;
       ll lo=1,hi=1e12,ans=-1;
       while(lo<=hi){
        ll mid=(lo+hi+1)/2;
        ll pos=getPos(mid,x,y);
        if(pos<k){
           lo=mid+1; 
        }
        else{
            ans=mid;
            hi=mid-1;
        }
       }
       if(getPos(ans,x,y)!=k) ans=-1;
       cout<<ans<<'\n';
    }
    return 0;
}