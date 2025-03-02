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
       ll a,b,n,m;cin>>a>>b>>n>>m;
       if(a<b) swap(a,b);
       //a>=b now 
       b-=m;
       if(b<0){
        cout<<"No\n";
        continue;
       }
       if(a+b<n){
        cout<<"No\n";
        continue;
       }
       cout<<"Yes\n";

    }
    return 0;
}