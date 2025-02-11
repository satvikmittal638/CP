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
       ll n,x,p;cin>>n>>x>>p;
       bool ok=0;
       for(ll q=1;q<=min(2*n,p);q++){
        if((x+q*(q+1)/2)%n==0){
            ok=1;
            break;
        }
       }
       cout<<(ok?"Yes":"No")<<"\n";
    }
    return 0;
}