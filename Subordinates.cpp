#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> dp;
void dfs(int node){
    for(auto child:adj[node]){
        dfs(child); // calculate subordinates for child
        // then use it to calculate subordinates for the parent
        dp[node]+=dp[child]+1; // no of subordinates of child+child itself
    }
}

int main()
{
    int n;cin>>n;
    adj.assign(n+1,vector<int>());
    for(int i=2;i<=n;i++){
        int boss;cin>>boss;
        adj[boss].emplace_back(i);
    }
    /*
    dp[i] denotes the no. of subordinates of employee i    
    */
    dp.assign(n+1,0);
    dfs(1);
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    return 0;
}