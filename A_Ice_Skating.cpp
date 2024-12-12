#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
void dfs(int v){
    visited[v]=1;
    for(auto u:adj[v]){
        if(!visited[u]) dfs(u);
    }
}

int main()
{
    int n;cin>>n;
    vector<int> x(n),y(n);
    for(int i=0;i<n;i++) cin>>x[i]>>y[i];
    adj.assign(n,vector<int>());
    visited.assign(n,0);
    for(int i=0;i<n;i++){
        // find neighbours of the vertex i(or vertex j)
        for(int j=i+1;j<n;j++){
            if(x[i]==x[j] || y[i]==y[j]){
                adj[i].emplace_back(j);
                adj[j].emplace_back(i);
            }
            
        }
    }
    int cnt_connected=0;
    for(int v=0;v<n;v++){
        if(!visited[v]) {
            cnt_connected++;
            dfs(v);
        }
    }
    cout<<cnt_connected-1;
    return 0;
}