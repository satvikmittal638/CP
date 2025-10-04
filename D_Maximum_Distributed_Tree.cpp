#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll MOD=1e9+7;
vector<vector<int>> adj;
vector<ll> szSubTree;

void dfs(int u,int p){
    for(auto v:adj[u]){
        if(v==p) continue;
        dfs(v,u);
        szSubTree[u]+=szSubTree[v];
    }
}
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       adj.assign(n,vector<int>());
       szSubTree.assign(n,1);// self counting=1
       for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
       }
       int m;cin>>m;
       vector<ll> p(m);for(auto &i:p) cin>>i;
       // pad to size n-1
       while(p.size()<n-1) p.push_back(1);

       sort(all(p));

       // reduce to size n-1 by taking the largest excess primes and combining them into single prime
       for(int i=n-1;i<m;i++){
        p[n-2]=(p[n-2]*p[i])%MOD;
       }
       /*
       root the tree at 0
       then subtree of u will correspond to edge b/w p[u] and u
       */
      dfs(0,-1);
      vector<ll> w;
       for(int u=1;u<n;u++){
        ll k=szSubTree[u];
        w.push_back(k*(n-k));
       }
       sort(all(w));
       ll ans=0ll;
       for(int i=0;i<n-1;i++){
        ans=(ans+((w[i]*p[i])%MOD))%MOD;
       }
       cout<<ans<<'\n';

    }
    return 0;
}