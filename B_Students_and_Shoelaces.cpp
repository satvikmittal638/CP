#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n,vector<int>());
    while(m--){
        int a,b;cin>>a>>b;
        a--;b--; //0-indexed now
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    // count degree of each vertex
    vector<int> deg(n,0);
    for(int v=0;v<n;v++){
        deg[v]=adj[v].size();
    }
    int cnt=0;
    vector<int> grp;
    do{
        grp.clear();
        for(int v=0;v<n;v++){
            if(deg[v]==1){
                grp.emplace_back(v);
            }
        }
        if(grp.size()>0){
            cnt++;
            for(auto v:grp){
                // decrement the degree of each of the neighbours
                for(auto u:adj[v]){
                    deg[u]--;
                }
                deg[v]=0;// remove from graph
            }
        }

    }while(grp.size());
    cout<<cnt;
    return 0;
}