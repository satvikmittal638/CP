#include<bits/stdc++.h>
using namespace std;

vector<int> kahnsTopo(vector<vector<int>>& adj,int n){
    vector<int> in_degree(n+1,0),order(n+1,-1);
    for(int v=1;v<=n;v++){
        for(auto u:adj[v]){
            in_degree[u]++;
        }
    }
    queue<pair<int,int>> q; // lvl->v
    for(int v=1;v<=n;v++){
        if(in_degree[v]==0){
            q.push({1,v});
        }
    }
    while(!q.empty()){
        pair<int,int> at=q.front();
        // if the level was unoccupied
        if(order[at.first]==-1){
            order[at.first]=at.second;
        }
        // more than 1 elt on the same lvl-->no unique ordering possible
        else{
            return {-1};
        }
        q.pop();
        for(auto u:adj[at.second]){
            in_degree[u]--;
            if(in_degree[u]==0) q.push({at.first+1,u});
        }
    }

    // order contains seqeunce of Ais in descending order
    vector<int> ans(n+1);
    for(int i=n;i>=1;i--){
        ans[order[i]]=n-i+1;
    }
    return ans;


}

int main()
{
    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n+1,vector<int>());
    while(m--){
        int x,y;cin>>x>>y;
        adj[y].emplace_back(x);
    }
    auto ans=kahnsTopo(adj,n);
    if(ans[0]!=-1){
        cout<<"Yes\n";
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    }else{
        cout<<"No";
    }
    return 0;
}