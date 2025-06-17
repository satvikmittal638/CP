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
       ll n,x;cin>>n>>x;
       set<ll> ks;
       for(ll y=1;y*y<=(n+x);y++){
           ll k,lo,hi;
       if((n-x)%y==0){
        if(y%2==0){
            k=(n-x)/y + 1;
            lo=1+y*(k-1),hi=k+y*(k-1);
            if(lo<=n && n<=hi)ks.insert(k);
        }

        // check for other no. of the divisor pair
        ll z=(n-x)/y;
        if(z%2==0){
            k=(n-x)/z+1;
            lo=1+z*(k-1);
            hi=k+z*(k-1);
            if(lo<=n && n<=hi) ks.insert(k);
        }
       }
       if((n+x-2)%y==0){
        if(y%2==0){
            k=(n+x-2)/y + 1;
            lo=k+1+(y-2)*(k-1), hi=2*k-2 + (y-2)*(k-1);
            if(lo<=n && n<=hi) ks.insert(k);
        }

        // check for other no. of the divisor pair
        ll z=(n+x-2)/y;
        if(z%2==0){
            k=(n+x-2)/z+1;
            lo=k+1+(z-2)*(k-1);
            hi=2*k-2 + (z-2)*(k-1);
            if(lo<=n && n<=hi)ks.insert(k);
        }
       }
       }
    //    for(auto k:ks) cout<<k<<" ";
       cout<<ks.size()<<"\n";
    }
    return 0;
}