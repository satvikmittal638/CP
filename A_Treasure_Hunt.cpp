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
       ll x,y,a;cin>>x>>y>>a;
       a%=(x+y);
       if(x>a){
        cout<<"NO\n";
       }
       else{
        cout<<"YES\n";
       }
    }
    return 0;
}