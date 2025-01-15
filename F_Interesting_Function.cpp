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
       int l,r;cin>>l>>r;
       ll ans=0ll;
       while(r){
        ans+=r-l; // count least significant digit changes
        // do the same for next significant digit
        r/=10;
        l/=10;
       }
       cout<<ans<<"\n";
    }
    return 0;
}