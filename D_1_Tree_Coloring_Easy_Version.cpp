#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
vector<vector<int>> adj;
vector<int> cntDepth,cntChild;
void dfs(int u,int p,int d){
    cntDepth[d]++;
    for(auto v:adj[u]){
        if(v==p) continue; // only 1 back-edge for a tree
        dfs(v,u,d+1);
    }
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       adj.assign(n,vector<int>());
       cntDepth.assign(n,0);
       cntChild.assign(n,0);
       for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
       }
       // now we need no. of nodes at a given depth d 
       dfs(0,-1,0);
       // and no. of direct children of a node u
       cntChild[0]=adj[0].size(); // no backedge for root
       for(int u=1;u<n;u++){
        cntChild[u]=adj[u].size()-1; // 1 back-edge to parent
       }
       int ans=max(1+*max_element(all(cntChild)),*max_element(all(cntDepth)));
       cout<<ans<<'\n';
    }
    return 0;
}