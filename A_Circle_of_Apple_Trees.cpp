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
       int n;cin>>n;
       int x;
       vector<bool> vis(n+1,0);
       for(int i=0;i<n;i++) {
        cin>>x;
        vis[x]=1;
       }
       cout<<accumulate(all(vis),0)<<'\n';
    }
    return 0;
}