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
       ll a,b,k;cin>>a>>b>>k;
       ll p=gcd(a,b);
       a/=p;b/=p;
       if(k>=a && k>=b){
        cout<<1;
       }
       else{
        cout<<2;
       }
       cout<<"\n";
    }
    return 0;
}