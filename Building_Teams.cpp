#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> team;

// use 0/1 for coloring
bool dfs(int v,int color){
    team[v]=color;
    for(auto u:adj[v]){
        // -1 indicates a univisited node
        if(team[u]!=-1){
            // if 2 neighbours got same color
            if(team[u]==team[v]){
                return 0; // no team possible
            }
        }else{
            if(!dfs(u,!color)) return 0; // assign the neighbour a different team
        }
    }
    return 1;
}

int main()
{
    int n,m;cin>>n>>m;
    adj.assign(n+1,vector<int>());
    while(m--){
        int a,b;cin>>a>>b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    team.assign(n+1,-1); 
    // to handle disconnected components
    bool canMakeTeam=1;
    for(int v=1;v<=n;v++){
        if(team[v]==-1 && !dfs(v,0)){
            canMakeTeam=0;break;
        }
    }
    if(canMakeTeam){
        for(int i=1;i<=n;i++) cout<<team[i]+1<<" ";
    }else{
        cout<<"IMPOSSIBLE";
    }
    return 0;
}