#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n,k;cin>>n>>k;
    vector<vector<int>> adj(n,vector<int>());
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> siz(n,1),dep(n,0);
    // siz[u]=1 to include self by default
    vector<bool> vis(n,0);
    auto dfs = [&](auto&& self, int u, int d) -> void {
        vis[u] = 1;
        dep[u] = d;

        for (auto v : adj[u]) {
            if (!vis[v]) {
                self(self, v, d + 1);
                siz[u] += siz[v];  // Add child subtree size after visiting it
            }
        }
    };
    dfs(dfs, 0, 1);  // root has depth 1
    vector<ll> dif(n,0);
    for(int i=0;i<n;i++) dif[i]=siz[i]-dep[i];
    sort(rall(dif));
    ll ans=accumulate(dif.begin(),dif.begin()+(n-k),0ll);
    cout<<ans;
    return 0;
}