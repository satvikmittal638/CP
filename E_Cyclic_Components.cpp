#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()


int main()
{
fastio;
    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n+1,vector<int>());
    while(m--){
        int v,u;cin>>v>>u;
        adj[v].emplace_back(u);
        adj[u].emplace_back(v);
    }
    vector<bool> visited(n+1,0);
    function<void(int,bool&)> dfs=[&](int v,bool& isCycle){
        visited[v]=1;
        isCycle&=(adj[v].size()==2);
        for(auto u:adj[v]){
            if(!visited[u]) dfs(u,isCycle);
        }
    };
    int ans=0;
    for(int v=1;v<=n;v++){
        if(!visited[v]){
            bool isCycle=1;
            dfs(v,isCycle);
            ans+=isCycle;
        }
    }
    cout<<ans;
    return 0;
}