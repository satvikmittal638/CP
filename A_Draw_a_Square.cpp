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
       int l,r,d,u;cin>>l>>r>>d>>u;
       if(l==r && d==u && l==d) cout<<"Yes";
       else cout<<"No";
       cout<<"\n";
    }
    return 0;
}