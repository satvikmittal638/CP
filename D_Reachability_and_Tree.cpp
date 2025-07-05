#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

vector<bool> vis;

void dfs(int u,vector<vector<int>>& adj,bool into){
    vis[u]=1;
    for(auto v:adj[u]){
        if(vis[v]) continue;
        if(into){
            cout<<v+1<<" "<<u+1<<"\n"; // v->u(into the parent)
        }
        else{
            cout<<u+1<<" "<<v+1<<"\n"; // u->v(out from the parent)
        }
        dfs(v,adj,!into);
    }
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<vector<int>> adj(n,vector<int>());
       for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
       }
       // find a vertex of degree 2
       int r=-1;
       for(int i=0;i<n;i++){
        if(adj[i].size()==2){
            r=i;
            break;
        }
       }
       if(r==-1){
        cout<<"NO\n";
        continue;
       }
       vis.assign(n,0);
       cout<<"YES\n";
       int v=adj[r][0],u=adj[r][1];
       cout<<r+1<<" "<<v+1<<"\n"; // r->v
       cout<<u+1<<" "<<r+1<<"\n"; // u->r
       vis[r]=1;
       dfs(v,adj,1); // v is a collector
       dfs(u,adj,0); // u is a distributor
    }
    return 0;
}