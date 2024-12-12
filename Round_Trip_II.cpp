#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited,recSt;
vector<int> parent;
int cycle_start,cycle_end;


bool dfs(int v){
    visited[v]=1;recSt[v]=1;
    for(auto u:adj[v]){
        if(!visited[u]){
            parent[u]=v;
            if(dfs(u)) return 1;
        }
        // if the neighbour is visited and it is present in the current recursion stack
        else if(recSt[u]) {
            cycle_start=u;
            cycle_end=v;
            return 1;
        }
    }
    recSt[v]=0; // after traversing all the neighbours, backtrack to original recursive stack
    
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.assign(n + 1, vector<int>());
    
    // directed graph a-->b
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
    }
    visited.assign(n+1,0);
    recSt.assign(n+1,0);
    parent.assign(n+1,-1);

    bool cycleFound=0;
    for(int v=1;v<=n;v++){
        if(!visited[v] && dfs(v)) {
            cycleFound=1;
            break;
        }
    }
    if(cycleFound){
        vector<int> cycle;
        for(int v=cycle_end;v!=cycle_start;v=parent[v]){
            cycle.emplace_back(v);
        }
        cycle.emplace_back(cycle_start);
        cycle.emplace_back(cycle_end); // close the cycle

        reverse(cycle.begin(),cycle.end()); // since we are tracing backwards, do the reverse to get original sequence

        cout<<cycle.size()<<"\n";
        for(auto v:cycle) cout<<v<<" ";
    }else{
        cout<<"IMPOSSIBLE";
    }


    

    return 0;
}