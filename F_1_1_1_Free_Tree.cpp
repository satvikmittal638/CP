#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

vector<vector<pair<int,ll>>> adj;
vector<map<int,ll>> dp;
/*
a[i] is color of node i
p[i] is parent of node i
cost[i] is cost of edge from node i to its parent(which is unique)
*/
vector<int> a,p,cost;
void dfs(int u,int par,ll &sum){
    p[u]=par;
    for(auto &[v,c]:adj[u]){
        if(v==par) {
            cost[u]=c;
            continue;
        }
        if(a[u]!=a[v]) sum+=c;
        dp[u][a[v]]+=c;
        dfs(v,u,sum);
    }
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,q;cin>>n>>q;
       a.assign(n,0);p.assign(n,0ll);cost.assign(n,0ll);
       adj.assign(n,vector<pair<int,ll>>());

       for(auto &i:a) cin>>i;
       for(int i=1;i<n;i++){
        int u,v,c;cin>>u>>v>>c;
        u--;v--;
        adj[u].emplace_back(v,c);
        adj[v].emplace_back(u,c);
       }
       /*
       Amortized space O(n)
       dp[i][j] denotes the sum of edge weights of children of node i having color j
       Root the tree at 0 to break the symmetry
       */
       dp.assign(n,map<int,ll>());
       //find initial sum
       ll ans=0ll;
       dfs(0,-1,ans);
       while(q--){
        int u,x;cin>>u>>x;u--;
        // no change is made
        if(a[u]==x) {
            cout<<ans<<"\n";
            continue;
        }

        //children with old color are paid now, but children with color x become free
        ans+=dp[u][a[u]]-dp[u][x];  

        if(p[u]!=-1){
            // adjust for parent
            if(a[p[u]]==a[u]) ans+=cost[u];// free became paid
            else if(a[p[u]]==x) ans-=cost[u]; // paid became free
    
            dp[p[u]][a[u]]-=cost[u]; // p[u] lost a child of old color
            dp[p[u]][x]+=cost[u]; // p[u] got a child of color x
        }
        a[u]=x;
        cout<<ans<<"\n";
       }
    }
    return 0;
}