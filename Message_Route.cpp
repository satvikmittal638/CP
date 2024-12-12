#include<bits/stdc++.h>
using namespace std;


vector<int> bfs(vector<vector<int>>& adjLst,int n){
    vector<int> parent(n+1,0);
    vector<bool> visited(n+1,0);
    queue<int> q;
    q.push(1);visited[1]=1; // send a msg from comp-1
    while(!q.empty()){
        int v=q.front();
        q.pop();
      
        visited[v]=1;
        vector<int> nghbrs=adjLst[v];
        for(auto node:nghbrs){
            if(!visited[node]){
                visited[node]=1;
                q.push(node);
                parent[node]=v;
            }
       }
    }
     // Check if `n` is reachable
    if (!visited[n])
        return {}; // Return an empty path if `n` is not reachable

    // Construct the path from 1 to n
    vector<int> path;
    for (int node = n; node != 0; node = parent[node]) {
        path.push_back(node);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    int n,m;cin>>n>>m;
    // adjacency list representation(1 based indexing)
    vector<vector<int>> adjLst(n+1,vector<int>());
    while (m--)
    {
        int a,b;cin>>a>>b;
        // undirected graph
        adjLst[a].emplace_back(b);
        adjLst[b].emplace_back(a);
    }
    vector<int> path=bfs(adjLst,n);
    if(path.size()>0){
        cout<<path.size()<<"\n";
        for(auto e:path) cout<<e<<" ";
    }else{
        cout<<"IMPOSSIBLE";
    }
    return 0;
}