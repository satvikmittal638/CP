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
       string x;cin>>x;
       int ans=10;
       for(auto c:x){
        ans=min(ans,c-'0');
       }
       cout<<ans<<"\n";
    }
    return 0;
}