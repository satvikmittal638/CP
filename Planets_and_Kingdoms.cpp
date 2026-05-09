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
void dfs(vector<vector<int>>& adj,int u,vector<int>& out){
    vis[u]=1;
    for(auto v:adj[u]){
        if(vis[v]) continue;
        dfs(adj,v,out);
    }
    out.push_back(u);
}
int main()
{
fastio;
    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n),adj_rev(n);
    while(m--){
        int a,b;cin>>a>>b;a--;b--;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }
    // order vertices in increasing order of exit times
    vector<int> order;
    vis.assign(n,0);
    for(int u=0;u<n;u++) if(!vis[u])dfs(adj,u,order);
    reverse(all(order));

    // expand SCC from maximal tout vertex
    vector<int> root(n,-1);
    int ctr=1;
    vis.assign(n,0);
    for(auto u:order){
        if(vis[u]) continue;
        vector<int> component;
        dfs(adj_rev,u,component);
        for(auto v:component) root[v]=ctr;

        ctr++;
    }
    cout<<ctr-1<<'\n';
    for(auto r:root) cout<<r<<' ';
    cout<<'\n';

    return 0;
}