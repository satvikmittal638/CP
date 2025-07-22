#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

bool dfs(vector<vector<pair<int,int>>>& adj, vector<int>& val, int u, int par_val, vector<int>& cnt) {
    val[u] = par_val;
    cnt[par_val]++;
    
    for (auto [v, edgeVal] : adj[u]) {
        int childVal = (edgeVal == 1 ? par_val : !par_val);
        if (val[v]==-1) {
            if (!dfs(adj, val, v, childVal, cnt)) return 0; // contradiction detected
        } else if (val[v] != childVal) {
            return 0; // contradiction detected
        }
    }
    return 1; // no contradiction
}
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,m;cin>>n>>m;
       vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>()); // {u,val}
       // 0 for imposter, 1 for crewmate
       bool ok=1;
       while(m--){
        int i,j,val=0;
        string c;
        cin>>i>>j>>c;i--;j--;
        val=c=="crewmate";
        // contradicting edge already present
        // if(adj[i].count({j,!val})){
        //     ok=0;
        // }
        adj[i].push_back({j,val});
        adj[j].push_back({i,val});
       }
       vector<int> cnt(2,0);
       vector<int> val(n, -1); // assigned values
       int ans=0;
        for(int i = 0; i < n; i++) {
            if (val[i]!=-1) continue;
            cnt.assign(2, 0);
            if (!dfs(adj, val, i, 0, cnt)) {
                ok = 0;
                break;
            }
            ans += max(cnt[0], cnt[1]);
        }
        if(!ok) ans=-1;
       cout<<ans<<"\n";

    }
    return 0;
}