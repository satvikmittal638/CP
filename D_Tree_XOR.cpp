#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
ll n;
vector<vector<int>> adj;
vector<ll> a,ans,szSubT;

// computes sizes of subtree when rooted at 0 and also the ans
void dfs1(int u, int p){
    for(auto v:adj[u]){
        if(v==p) continue;
        dfs1(v,u);// compute for children
        szSubT[u]+=szSubT[v];
        ans[0]+=(a[v]^a[u])*szSubT[v]; // apply operation on v,child of u
    }
}
// compute ans by shifting roots to the neighbours
void dfs2(int u,int p){
    for(auto v:adj[u]){
        if(v==p) continue;
// consider the edge u-v
// let the root shift from u to v
//  v and its descendants remain unchanged
// u and its predecessors experience the change
// the change in cost is still local, which can be computed by only considerin the edge u-v
// remove (a[u]^a[v])*size[v] -> corresponds to subtree of v
// add (a[u]^a[v])*(n-size[v])-> this is size of new subtree of u
        ans[v]=ans[u]+(a[u]^a[v])*(n-2*szSubT[v]);
        dfs2(v,u);
    }
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       cin>>n;
       adj.assign(n,vector<int>());
       a.assign(n,0);
       ans.assign(n,0);
       szSubT.assign(n,1); // include self
       for(auto &i:a) cin>>i;
       for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
       }
       dfs1(0,-1);
       dfs2(0,-1);
       for(auto e:ans) cout<<e<<' ';
       cout<<'\n';
    }
    return 0;
}