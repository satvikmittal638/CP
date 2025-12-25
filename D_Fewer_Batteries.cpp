#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
using pll=pair<ll,ll>;
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
        int n,m;cin>>n>>m;
        vector<int> b(n);for(auto &i:b) cin>>i;
        vector<vector<pll>> adj(n); // {node,weight}
        while(m--){
            ll s,t,w;cin>>s>>t>>w;s--;t--;
            adj[s].emplace_back(t,w);
        }
        // dp1[u] is minm batteries taken for 0->u
        // dp2[u] is maxm batteries left from 0->u
        vector<ll> dp1(n,0),dp2(n,0);
        vector<bool> vis(n,0);
        auto dfs = [&](auto&& self, int u) -> void {
            vis[u]=1;
            for (const auto &[v,w] : adj[u]) {
                if(!vis[v]){
                    dp2[v]=max(dp2[v],dp2[u]+b[u]);
                    // sufficient batteries already, no more needed
                    if(dp1[u]>=w){
                        dp1[v]=min(dp1[v],dp1[u]);
                        self(self, v);
                    }
                    else{
                        if(w-dp1[u]<=dp2[v]){
                            dp2[v]-=w-dp1[u]; // take some batteries from the unused
                            dp1[v]=w;
                            self(self, v);
                        }
                        else{
                            // can't reach v, so don't call for its neighbours
                            dp1[v]=-1;
                        }
                    }
                }
            }
        };

        dfs(dfs,0);
        if(!vis[n-1]) dp1[n-1]=-1; // (n-1) is disconnected
        cout<<dp1[n-1]<<'\n';
    }
    return 0;
}