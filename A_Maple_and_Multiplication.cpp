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
       int a,b;cin>>a>>b;
       int ans=0;
       if(b==a) ans=0;
       else if(b%a==0 || a%b==0) ans=1;
       else ans=2;
       cout<<ans<<'\n';
    }
    return 0;
}