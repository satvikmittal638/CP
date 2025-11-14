#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
vector<vector<int>> adj;
vector<int> sz;
void dfs(int u,int p){
    for(auto v:adj[u]){
        if(v==p) continue;
        dfs(v,u);// find subtree sizes of children
        sz[u]+=sz[v];// then add
    }
}
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,k;cin>>n>>k;
       adj.assign(n,vector<int>());
       for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
       }
       sz.assign(n,1);// subtree of u includes u also
       dfs(0,-1); // root at 0(arbitrary choice)
       ll ans=0ll;
       for(int u=0;u<n;u++){
        // choose any node outside the subtree of u
        if(sz[u]>=k) ans+=n-sz[u];
        // choose any node from the subtree of u
        if((n-sz[u])>=k) ans+=sz[u];
       }
       cout<<ans+n<<'\n'; // ans is atleast n since root itself can form a tree of size>=k(as k<=n holds)
    }
    return 0;
}