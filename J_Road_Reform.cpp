#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()


struct Edge {
    int u, v;
    ll wt;
    Edge(int _u, int _v, ll _wt) : u(_u), v(_v), wt(_wt) {}
};

vector<Edge> adj;
vector<vector<int>> adj2;
vector<bool> vis;
void dfs(ll v) {
    vis[v] = 1 ;
    for (auto u : adj2[v]) {
        if (!vis[u])
            dfs(u);
    }
}

// DSU
vector<int> parent, rnk;

void make_set(int v) {
    parent[v] = v;
    rnk[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}
//

int main()
{
fastio;
    ll tt;cin>>tt;
    while(tt--){
       ll n,m,k;cin>>n>>m>>k;
       adj.clear();
       adj2.assign(n,vector<int>());

       for(ll i=0;i<m;i++){
        ll x,y,s;cin>>x>>y>>s;x--;y--;
        if(x>y) swap(x,y); 
        // x<y WLOG
        adj.emplace_back(x,y,s);

        // adj2 has edges with s<=k only
        if(s<=k){
            adj2[x].emplace_back(y);
            adj2[y].emplace_back(x);
        }
       }
       ll ans1=LLONG_MAX;
       // check if adj2 is connected
       vis.assign(n,0);
       dfs(0);
       
       // If there remains no unvisited node, adj2 is connected
       if(count(all(vis),0)==0){
        for(Edge e:adj){
            ans1=min(ans1,abs(e.wt-k));
        }
       }

       // make MST over adj for edge weight max(0,s[i]-k)
       
        parent.assign(n,-1);
        rnk.assign(n,0);
        for (int i = 0; i < n; i++) make_set(i);

        // use edge weight as max(0,s[i]-k)
        sort(all(adj), [k](const Edge &a, const Edge &b) {
            return max(0ll, a.wt - k) < max(0ll, b.wt - k);
        });

        ll ans2=0ll;
        for (Edge e : adj) {
            if (find_set(e.u) != find_set(e.v)) {
                ans2 += max(0ll,e.wt-k);
                union_sets(e.u, e.v);
            }
        }
        if(ans2==0) ans2=LLONG_MAX;
        // cout<<ans1<<" "<<ans2<<" ";
        cout<<min(ans1,ans2)<<"\n";
    }
    return 0;
}