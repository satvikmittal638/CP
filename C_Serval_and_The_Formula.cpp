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
       ll x,y,k;cin>>x>>y;{
        if(x==y) cout<<"-1\n";
        else{
            cout<<(1ll<<50)-max(x,y)<<"\n";
        }
       }
    }
    return 0;
}