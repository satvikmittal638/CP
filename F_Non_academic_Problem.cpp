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

// Source: CP-algorithms
ll n;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> tin, low, subtreeSz;
int timer;

void dfs(int v, int p,ll &ans) {
    visited[v] = 1;
    tin[v] = low[v] = timer++;
    bool parent_skipped = 0;
    for (int to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = 1;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v,ans);
            subtreeSz[v]+=subtreeSz[to];
            low[v] = min(low[v], low[to]);
            // bridge found
            // subtree root at 'to'
            if (low[to] > tin[v]){
                ll k1=subtreeSz[to],k2=n-k1;
                ans=min(ans,k1*(k1-1)/2 + k2*(k2-1)/2);
            }
        }
    }
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int m;cin>>n>>m;
       // initialize
       adj.assign(n,vector<int>());
       timer = 0;
        visited.assign(n, 0);
        tin.assign(n, -1);
        low.assign(n, -1);
        subtreeSz.assign(n,1);

       while(m--){
        int u,v;cin>>u>>v;u--;v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
       }
       ll ans=n*(n-1)/2;
       dfs(0,-1,ans);
       cout<<ans<<'\n';

    }
    return 0;
}