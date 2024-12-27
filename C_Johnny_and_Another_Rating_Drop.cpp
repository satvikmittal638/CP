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
       // for n=2^p, ans is 2^p+1 -1
       // final ans is just doing this for all position p with a set bit
       // since ans[s,s+2^i] = ans[0,2^i] :)
       ll ans=0ll;
       for(int i=0;i<64;i++){
        if(n&(1ll<<i))
            ans+=(1ll<<(i+1))-1;
       }
       cout<<ans<<"\n";
    }
    return 0;
}