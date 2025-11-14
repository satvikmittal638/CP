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
       ll r,x,d,n;cin>>r>>x>>d>>n;
       string s;cin>>s;
       int ans=0;
       for(auto c:s){
        if(c=='1'){
            r=max(0ll,r-d);
            ans++;
        }
        else{
            if(r<x){
                ans++;
                r=max(0ll,r-d);
            }
        }
       }
       cout<<ans<<'\n';
    }
    return 0;
}