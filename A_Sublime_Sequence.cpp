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
       int n,x;cin>>x>>n;
       int ans;
       if(n%2==0) ans=0;
       else ans=x;
       cout<<ans<<'\n';
    }
    return 0;
}