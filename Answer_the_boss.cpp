#include<bits/stdc++.h>
using namespace std;


vector<pair<int,int>> kahnsTopo(vector<vector<int>> adj,int n){
    vector<int> in_degree(n,0);
    vector<pair<int,int>> order; // rank->employee
    for(int v=0;v<n;v++){
        for(auto u:adj[v]){
            in_degree[u]++;
        }
    }
    queue<pair<int,int>> q;
    for(int v=0;v<n;v++){
        if(in_degree[v]==0) q.push({1,v});
    }
    while(!q.empty()){
        pair<int,int> at=q.front();
        order.emplace_back(at);
        q.pop();
        for(auto to:adj[at.second]){
            in_degree[to]--;
            if(in_degree[to]==0) q.push({at.first+1,to});
        }
    }
    return order;
}

bool comp(pair<int,int> p1,pair<int,int> p2){
    // if rank is same then sort lexicographically
    if(p1.first==p2.first){
        return p1.second<p2.second;
    }
    return p1.first<p2.first;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int tt;cin>>tt;
    for(int i=1;i<=tt;i++){
        int n,r;cin>>n>>r;
        // 0-indexed
        vector<vector<int>> adj(n,vector<int>());
        // r2-->r1
        while(r--){
            int r1,r2;cin>>r1>>r2;
            adj[r2].emplace_back(r1);
        }
        auto order=kahnsTopo(adj,n);
        // sort lexicographically if rank is same
        sort(order.begin(),order.end(),comp);
        cout<<"Scenario #"<<i<<":\n";
        for(auto p:order){
            cout<<p.first<<" "<<p.second<<"\n";
        }

    }
    return 0;
}