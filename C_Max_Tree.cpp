#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

// Source:CP-algorithms
int n;
vector<vector<int>> adj; 
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = 1;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, 0);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       cin>>n;
       adj.assign(n,vector<int>());
       for(int i=1;i<n;i++){
        int u,v,x,y;cin>>u>>v>>x>>y;u--;v--;
        // make directed graph to always include max(x,y) in the sum
        if(x<y) adj[u].push_back(v);
        else adj[v].push_back(u);
       }
       topological_sort();
    //    for(auto e: ans) cout<<e<<" ";
       // fill the no.s in increasing order
       vector<int> p(n);
       int x=1;
       for(auto e:ans){
            p[e]=x++;
       }
       for(auto e:p) cout<<e<<' ';
       cout<<'\n';

    }
    return 0;
}