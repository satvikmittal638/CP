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
       ll a,b;cin>>a>>b;
       if((a%2!=0 && b%2==0 && b%4!=0) || (a%2==0 && b%2!=0)){
        cout<<"-1\n";
        continue;
       }
       ll ans=0ll;
       if(b%2!=0){
        ans=a*b+1ll;
       }
       // b is even
       else{
           a*=b/2;
        b=2;
        ans=a+b;
       }
       
    //    cout<<a<<" "<<b;
       cout<<ans<<'\n';
    }
    return 0;
}