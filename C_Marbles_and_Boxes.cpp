#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    // precompute all derrangement values
    ll d[21];
    d[1]=0;d[2]=1;
    for(int i=3;i<=20;i++){
        d[i]=(i-1)*(d[i-1]+d[i-2]);
    }
    int tt;cin>>tt;
    while(tt--){
       ll n;cin>>n;
       cout<<(d[n]+n*d[n-1])<<"\n";
    }
    return 0;
}