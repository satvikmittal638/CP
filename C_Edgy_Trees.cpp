#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int mod=1e9+7;
vector<vector<int>> adj;
vector<bool> vis;
// calculates the size of the connected component
void dfs(int u,ll &sz){
    vis[u]=1;
    for(auto v:adj[u]){
        if(vis[v]) continue;
        sz++;
        dfs(v,sz);
    }
}

ll modexp(ll base, ll exp) {
    ll res = 1ll;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2ll;
    }
    return res;
}

int main()
{
fastio;
    ll n,k;cin>>n>>k;
    adj.assign(n,vector<int>());
    vis.assign(n,0);
    for(int i=1;i<n;i++){
        int u,v,x;cin>>u>>v>>x;u--;v--;
        // add red edge only
        if(x==0){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    ll ans=modexp(n,k);
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        ll sz=1ll;dfs(i,sz);
        // cout<<sz<<" ";
        ans=(ans-modexp(sz,k)+mod)%mod;
    }
    cout<<ans;

    return 0;
}