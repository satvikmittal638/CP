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
       ll x; cin>>x;
        // find number of digits=k
        ll p = 1;
        while(p <= x) p *= 10; // now p = 10^k
        p*=10; // p=10^(k+1)>(x+1)

        ll y=p-(x+1);
        cout<<y<<'\n';

    }
    return 0;
}