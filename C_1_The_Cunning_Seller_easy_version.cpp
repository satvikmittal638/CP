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
       ll p=1,power=3;
       ll ans=(n%3)*3;// for x=0
       n/=3;
       while(n){
        int d=n%3;
        ans+=d*(power/3)*(9+p);
        power*=3ll;
        p++;
        n/=3;
        // cout<<ans<<" ";
       }
       cout<<ans<<"\n";
    }
    return 0;
}