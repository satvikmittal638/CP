#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int MOD=998244353;
vector<vector<int>> adj;
vector<int> d;
void dfs(int u){
    for(auto v:adj[u]){
        d[v]=d[u]+1;
        dfs(v);
    }
}
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       // 0 has no parent(its root)
       // p[i] is parent of node i+1
       vector<int> p(n-1),dp(n,1);for(auto &i:p) {cin>>i;i--;}
       adj.assign(n,vector<int>());
       d.assign(n,0);
       for(int i=0;i<n-1;i++) adj[p[i]].push_back(i+1);
       dfs(0);
    //    for(auto e:d) cout<<e<<" ";
    //    cout<<"\n";
        // adj2[i] is list of nodes with depth=i
        vector<vector<int>> adj2(n,vector<int>());// max depth=n-1 for straight chain tree
        for(int i=0;i<n;i++){
            adj2[d[i]].push_back(i);
        }
        // now traverse the nodes in increasing order of depths
        // base case for root's immediate neighbours
        int s=0;
        for(auto v:adj2[1]) {
            // dp[v]=2; // same as dp[v]+=dp[0]
            s+=dp[v];
            s%=MOD;
        }
        for(int i=2;i<n;i++){
            int cur=0;
            for(auto v:adj2[i]){
                dp[v]=(s-dp[p[v-1]]+MOD)%MOD; // can come to this node from all nodes in the previous level except from its parent
                cur=(cur+dp[v])%MOD;
            }
            s=cur;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=(ans+dp[i])%MOD;
            // cout<<dp[i]<<' ';
        }
        cout<<ans<<'\n';
        // cout<<'\n';
        



    }
    return 0;
}