#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

#ifndef ONLINE_JUDGE
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
#else
#define error(args...)
#endif


vector<bool> vis;
void dfs(vector<int>& out, int u,vector<vector<int>>& adj){
    vis[u]=1;
    for(auto v:adj[u]){
        if(!vis[v]) dfs(out,v,adj);
    }
    out.push_back(u);
}
vector<ll> dp,cost;
ll solve(vector<vector<int>>& adj,int u){
    if(dp[u]!=-1) return dp[u];
    ll mx=0;
    for(auto v:adj[u]) mx=max(mx,solve(adj,v));
    return dp[u]=cost[u]+mx;
}
int main()
{
    fastio;
    int n,m;cin>>n>>m;
    vector<ll> k(n);for(auto &i:k) cin>>i;
    vector<vector<int>> adj(n),adj_rev(n);
    
    while(m--){
        int a,b;cin>>a>>b;a--;b--;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }
    vis.assign(n,0);
    vector<int> order;
    // get vertices ordered in ascending by exit times
    for(int i=0;i<n;i++){
        if(!vis[i]) dfs(order,i,adj);
    }
    reverse(all(order));
    // now run dfs from the maximal tout, i.e. first elt in order
    vis.assign(n,0);
    vector<ll> root(n,-1);
    cost.assign(n,0);
    for(auto u:order){
        if(vis[u]) continue;
        vector<int> component;
        dfs(component,u,adj_rev);
        int r=component.back();
        // compute the costs and unite the SCC
        for(auto v:component) {
            root[v]=r;
            cost[r]+=k[v];
        }
    }

    // now build the condensation graph with SCC as a supernode(their cost is stored in the costs array itself)
    vector<vector<int>> adj_cond(n);
    for(int u=0;u<n;u++){
        for(auto v:adj[u]){
            if(root[v]!=root[u]){
                adj_cond[root[v]].push_back(root[u]);
            }
        }
    }

    // dp[i] is maxm cost if I start at supernode i
    dp.assign(n,-1);
    ll ans=0ll;
    for(int u=0;u<n;u++){
        ans=max(ans,solve(adj_cond,root[u]));
    }
    cout<<ans;

    return 0;
}