#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
// TODO:check and debug
// Source:CP-algorithms
int n;
vector<vector<int>> adj; 
vector<vector<pair<int,int>>> bridges;

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = 1;
    tin[v] = low[v] = timer++;
    bool parent_skipped = 0;
    for (int to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = 1;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            // bridge is found, store it
            if (low[to] > tin[v]) {
                bridges.emplace_back(min(v,to),max(v,to));
            }
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, 0);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int m;cin>>n>>m;
       adj.assign(n,vector<int>());
       for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
       }
       // find all the bridges
       find_bridges();
       // now filter the bridges which lie on any path from 1->n

       // Run multi-source BFS from all nodes which are part of bridges
     
       vector<int> ans(n,-1);
     
       int t;cin>>t;
       while(t--){
        int c;cin>>c;c--;
        cout<<ans[c]<<" ";
       }
       cout<<'\n';
    }
    return 0;
}