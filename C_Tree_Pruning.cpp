#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<vector<int>> adj(n,vector<int>());
       for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
       }
       vector<bool> vis(n,0);
       /*
       a[i] denotes the depth of a node i
       b[i] denotes the (maxm depth wrt root=1) of a the subtree of i
       */
       vector<int> a(n,0),b(n,0);
       auto dfs=[&](auto &&self,int u,int dep)->void{
        vis[u]=1;
        a[u]=dep;
        for(auto v:adj[u]){
            if(!vis[v]){
                self(self,v,dep+1);
                b[u]=max(b[u],b[v]+1);
            }
        }
       };
       dfs(dfs,0,0);
    //    for(auto e:a) cout<<e<<" ";
    //    cout<<"\n";
    //    for(auto e:b) cout<<e<<" ";
       /*
       for a given d, all nodes with a[i]<=d<=b[i] will survive
       Minimize dead nodes=maximize alive nodes
       so d will belong to maxm no. of intersecting intervals
       So now we need to find the maxm no. of intersecting intervals
       Now its same as finding "Minm rooms needed for all meetings to be hosted given their starting and ending time"
       */

       // +1 for a[i]
       // -1 for b[i]+1
       vector<pair<int,int>> itvls;
       for(int i=0;i<n;i++){
        itvls.push_back({a[i],1});
        b[i]+=a[i];
        itvls.push_back({b[i]+1,-1});
       }
       sort(all(itvls));
       int ans=0,cur=0;
       for(auto &[t,val]:itvls){
        cur+=val;
        ans=max(ans,cur);
       }
       cout<<ans<<"\n";
       
    }
    return 0;
}