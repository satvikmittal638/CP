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
       ll l,a,b;cin>>l>>a>>b;
       ll ans=0ll;
       for(int i=0;i<=10000;i++){
        ans=max(ans,(a+b*i)%l);
       }
       cout<<ans<<'\n';
    }
    return 0;
}