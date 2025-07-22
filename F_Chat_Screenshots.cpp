#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

// Source:CP-algorithms
bool dfs(vector<int>& color,vector<set<int>>& adj,int v) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            if (dfs(color,adj,u))
                return 1;
        } else if (color[u] == 1) {
            return 1;
        }
    }
    color[v] = 2;
    return 0;
}


int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,k;cin>>n>>k;
       vector<set<int>> adj(n);
       // build a DAG
       while(k--){
        vector<int> ss(n);for(auto &i:ss) {cin>>i;i--;}
        // skip the 1st
        for(int i=1;i<n-1;i++){
            adj[ss[i]].insert(ss[i+1]);
        }
       }
       // for a valid Topo-sort, graph mustn't have cycles
       vector<int> color(n,0);
       bool ok=1;
         for (int v = 0; v < n; v++) {
            if (color[v] == 0 && dfs(color,adj,v)){
                ok=0;break;
            }
        }

       cout<<(ok?"YES":"NO")<<"\n";
    }
    return 0;
}