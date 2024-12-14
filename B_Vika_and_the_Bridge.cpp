#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,k;cin>>n>>k;
       vector<int> c(n);
       vector<vector<int>> adj(k+1,vector<int>()); // stores all indices of a particular color
       for(int i=0;i<n;i++) {
        cin>>c[i];
        adj[c[i]].emplace_back(i);
       }
       int ans=INT_MAX;
       for(int c=1;c<=k;c++){
        if(adj[c].empty()) continue;
        vector<int> skips;
        skips.emplace_back(adj[c][0]);//skip from start
        for(int j=1;j<adj[c].size();j++){
            skips.emplace_back(adj[c][j]-adj[c][j-1]-1);
        }
        skips.emplace_back(n-adj[c].back()-1);
        // can do w/o sorting as well
        sort(skips.rbegin(),skips.rend());
        ans=min(max((skips[0])/2,skips[1]),ans);
       }
       cout<<ans<<"\n";

       
    }
    return 0;
}