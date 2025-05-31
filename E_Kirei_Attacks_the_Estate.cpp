#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

void dfs(vector<ll>& threat,vector<vector<int>> &adj,vector<bool>& visited,int u,int lvl,ll cur_sum,int c){
    visited[u]=1;
    if(lvl%2==0) threat[u]=max(threat[u],threat[])
    for(auto v:adj[u]){
        if(!visited[u]) dfs()
    }
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n);for(auto &i:a) cin>>i;
       vector<vector<int>> adj(n,vector<int>());
       for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
       }
       vector<ll> threat(n,LLONG_MIN);
       vector<bool> visited(n,0);
    }
    return 0;
}