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
       ll k=(1+sqrt(1+8*n))/2;
       ll ans=k+(n-k*(k-1)/2); // if additional balls required,take them of repeated type
       cout<<ans<<"\n"; 
    }
    return 0;
}