#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
<<<<<<< HEAD
=======

int n,a,b;
vector<vector<pair<int,int>>> adj;
set<int> s;

void dfs1(int u, int x,int par){
    if(u==b) return; // don't cross b
    s.insert(x);
    for(auto &[v, w] : adj[u]){
        if(v==par) continue;
        dfs1(v,x^w,u);
    }
}

bool dfs2(int u,int x,int par){
    if(u!=b && s.count(x)) return 1;
    for(auto &[v,w]:adj[u]){
        if(v==par) continue;
        if(dfs2(v,x^w,u)) return 1;
    }
    return 0;
}

>>>>>>> 29f0909 (solved some 1700)
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
<<<<<<< HEAD
       int n,a,b;cin>>n>>a>>b;
       vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());//{neighbour,weight}
=======
        s.clear();// reset
       cin>>n>>a>>b;a--;b--;
       adj.assign(n,vector<pair<int,int>>());
>>>>>>> 29f0909 (solved some 1700)
       for(int i=1;i<n;i++){
        int u,v,w;cin>>u>>v>>w;u--;v--;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
       }
<<<<<<< HEAD
       auto dfs=[&]()
=======
       /*
       move from a->c then teleport to d and move from d->b
       on path from a->c, we can't cross b
       also d can't be same as b
       */
       dfs1(a,0,-1);
       cout<<(dfs2(b,0,-1)?"YES":"NO")<<"\n";
       
>>>>>>> 29f0909 (solved some 1700)
    }
    return 0;
}