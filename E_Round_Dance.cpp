#include<bits/stdc++.h>
using namespace std;

// Use a set to prevent duplicate entries from the input !!
vector<set<int>> adj;
vector<bool> visited;

bool dfs(int par,int v){
    visited[v]=1;
    for(auto u:adj[v]){
        if(u==par) continue; // skip edge back to parent
        if(visited[u]) {
            return 1;// cycle found
        }
        else{
            if(dfs(v,u)) return 1; // find cycle in more depths
        }
    }
    return 0;
}


int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       // undirected graph
       adj.assign(n+1,set<int>());
       for(int v=1;v<=n;v++){
        int a;cin>>a;
        adj[v].insert(a);
        adj[a].insert(v);
       }

       visited.assign(n+1,0);
        int cnt_cyclic=0,cnt_acyclic=0;
        // to iterate all connected components
       for(int v=1;v<=n;v++){
        if(!visited[v]){
            if(dfs(-1,v)){
                cnt_cyclic++;
            }else{
                cnt_acyclic++;
            }
        }
       }
       int minAns=(cnt_acyclic>0)+cnt_cyclic,maxAns=cnt_cyclic+cnt_acyclic;
       cout<<minAns<<" "<<maxAns<<"\n";
    // cout<<cnt_acyclic<<" "<<cnt_cyclic<<"\n";
    }
    return 0;
}