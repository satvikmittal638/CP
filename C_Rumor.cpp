#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> c;
void dfs(int v,int& minCost){
    minCost=min(minCost,c[v]);
    visited[v]=1;
    for(auto u:adj[v]){
        if(!visited[u]){
            dfs(u,minCost);
        }
    }
}

int main()
{
    int n,m;cin>>n>>m;
    c.assign(n+1,0);
    for(int i=1;i<=n;i++) cin>>c[i];
    adj.assign(n+1,vector<int>());
    visited.assign(n+1,0);
    while(m--){
        int x,y;cin>>x>>y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    long long totalCost=0;
    for(int v=1;v<=n;v++){
        int minCost=INT_MAX;
        if(!visited[v]){
            dfs(v,minCost);
            totalCost+=minCost;
        }
    }
    cout<<totalCost;
    return 0;
}