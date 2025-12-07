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
       int n,y,r,ans=0;cin>>n>>y>>r;
       ans+=min(r,n);
       n-=min(r,n);
       ans+=min(n,y/2);
       cout<<ans<<'\n';
       
    }
    return 0;
}