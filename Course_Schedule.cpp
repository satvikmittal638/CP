#include<bits/stdc++.h>
using namespace std;

// returns topo sort for a graph with n vertices
vector<int> kahnsTopo(vector<vector<int>>& adj,int n){
    // count in-degree of each vertex
    vector<int> in_degree(n+1,0);
    for(int v=1;v<=n;v++){
        for(auto u:adj[v]){
            in_degree[u]++;
        }
    }
    // start with vertices with 0 in-degree
    queue<int> q;
    for(int v=1;v<=n;v++){
        if(in_degree[v]==0) q.push(v);
    }
    vector<int> topoOrder;
    while(!q.empty()){
        int at=q.front();
        q.pop();
        topoOrder.emplace_back(at);
        // decrement the in-degree of the children by 1
        for(auto to:adj[at]){
            in_degree[to]--;
            // remove the parent and check if the indegree becomes 0
            // if yes then add to queue
            if(in_degree[to]==0) q.push(to);
        }

    }
    return topoOrder;
}

int main()
{
    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n+1,vector<int>());
    // Directed graph
    while(m--){
        int a,b;cin>>a>>b;
        adj[a].emplace_back(b);
    }
    vector<int> topoOrder=kahnsTopo(adj,n);
    if(topoOrder.size()==n){
        for(auto e:topoOrder) cout<<e<<" ";
    }
    else{
        cout<<"IMPOSSIBLE";
    }
    


    return 0;
}