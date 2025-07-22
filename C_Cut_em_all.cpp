#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

void dfs(int u,vector<vector<int>>& adj,vector<bool>& vis,vector<int>& siz){
    vis[u]=1;
    for(auto v:adj[u]){
        if(!vis[v]){
            dfs(v,adj,vis,siz);
            siz[u]+=siz[v];
        }
    }
}

int main()
{
fastio;
    int n;cin>>n;
    if(n%2!=0){
        cout<<"-1";
        return 0;
    }
    vector<vector<int>> adj(n,vector<int>());
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n,0);
    vector<int> siz(n,1);
    dfs(0,adj,vis,siz);
    int ans=0;
    for(auto sz:siz) {
        // cout<<sz<<" ";
        ans+=(sz!=n && sz%2==0);
    }
    cout<<ans;
    return 0;
}