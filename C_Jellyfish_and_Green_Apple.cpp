#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    ll tt;cin>>tt;
    while(tt--){
       ll n,m;cin>>n>>m;
       n%=m;
       ll a=n/gcd(n,m),b=m/gcd(n,m);
       if(__builtin_popcountll(b)>1){
        cout<<"-1\n";
        continue;
       }
       ll ans=m*__builtin_popcountll(a)-n;
       cout<<ans<<"\n";
    }
    return 0;
}