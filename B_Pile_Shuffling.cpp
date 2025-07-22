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
       int n;cin>>n;
       ll ans=0ll;
       for(int i=0;i<n;i++){
        ll a,b,c,d;cin>>a>>b>>c>>d;
        if(b>d) ans+=a+(b-d); // remove all 0s from top and excess 1s
        else if(a>c) ans+=a-c; // remove excess 0s
       }
       cout<<ans<<"\n";
    }
    return 0;
}