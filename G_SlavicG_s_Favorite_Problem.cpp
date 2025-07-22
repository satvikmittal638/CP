#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,a,b;cin>>n>>a>>b;
       vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());//{neighbour,weight}
       for(int i=1;i<n;i++){
        int u,v,w;cin>>u>>v>>w;u--;v--;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
       }
       auto dfs=[&]()
    }
    return 0;
}