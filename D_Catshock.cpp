#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
vector<vector<int>> adj;
vector<int> d;
void dfs1(int u,int par){
    if(par == -1) d[u] = 0;
    else d[u] = d[par] + 1;
    for(auto v : adj[u]) {
        if(v == par) continue;
        dfs1(v, u);
    }
}
int cur;
// unfolds from bottom to up, stack-style
void dfs2(int u,int par,vector<pair<int,int>>& ans,int n){
    // leaf node!=n-1 found, so we can safely delete it
    for(auto v:adj[u]){
        if(v==par) continue;
        dfs2(v,u,ans,n);// dig deep down
    }
    // same color,apply op-1 once to flip the color
    // then delete leaf u
    if(d[u]%2==cur){
        ans.emplace_back(1,-1);
        cur=!cur;
    }
    // different color, apply op-1 twice to prevent using op-2 consecutively, then delete u
    else{
        ans.emplace_back(1,-1);
        ans.emplace_back(1,-1);
    }
    ans.emplace_back(2,u+1);
}
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       adj.assign(n,vector<int>());
       d.assign(n,0);
       for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
       }
       dfs1(n-1,-1);// to build depth array
       
       // now nodes with even depth and nodes with odd depth form a bipartite graph
       // now keep deleting arbitrary leaf nodes!=n
       cur=d[0]%2;// initially on 0
       vector<pair<int,int>> ans;
       // prune all branches of the tree and leave the root (n-1) alone
        for (auto v : adj[n - 1]) {
            dfs2(v, n - 1, ans, n);
        }
       cout<<ans.size()<<'\n';
       for(auto &[t,v]:ans){
        if(t==1) cout<<1<<'\n';
        else cout<<2<<' '<<v<<'\n';
       }
    }
    return 0;
}