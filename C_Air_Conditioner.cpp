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
       ll mn=m,mx=m,prevT=0ll;
       bool ok=1;
       while(n--){
        ll t,l,h;cin>>t>>l>>h;
        // expand the possible range
        mx+=t-prevT;
        mn-=t-prevT;
        if(mx<l || mn>h){
            ok=0;
            break;
        }
        mx=min(mx,h);
        mn=max(mn,l);
        prevT=t;
        
       }
       cout<<(ok?"YES":"NO")<<"\n";
    }
    return 0;
}