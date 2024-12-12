#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> nonPrimes;

void getNonPrimes(int n){
    vector<bool> is_prime(n+1,1);
    is_prime[0]=is_prime[1]=0;
    for(int i=2;i*i<=n;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=n;j+=i){
                is_prime[j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!is_prime[i]) nonPrimes.emplace_back(i);
    }
}

vector<vector<int>> branches;
void dfs(int v){
    vector<int> branch;
    bool isLeafNode=1;
    visited[v]=1;
    for(auto u:adj[v]){
        if(!visited[u]){
            isLeafNode=0;
            branch.emplace_back(u);
           dfs(u);
        }
    }
    // we reached the leaf node and hence a branch ends
    if(isLeafNode) branches.emplace_back(branch);
}

int main()
{
    getNonPrimes(2*1e5);
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       adj.assign(n+1,vector<int>());
       visited.assign(n+1,0);
       for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
       }
       vector<int> a(n);
       sort(branches.rbegin(),branches.rend(),[](vector<int>v1,vector<int> v2){
        return v1.size()<v2.size();
       });

       for(int i=0;i<branches.size();i++){
        vector<int> branch=branches[i];
        for(int j=0;j<branch.size();j++){
            if(branch[j]!=0){
                a[branch[j]-1]=a[branch[j-1]-1] + nonPrimes[i];
            }
        }
       }
       for(auto e:a) cout<<e<<" ";
       cout<<"\n";

    }
    return 0;
}