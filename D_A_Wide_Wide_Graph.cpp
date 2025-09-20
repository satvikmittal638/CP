#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
vector<vector<int>> adj;
void dfs(int u,int par,int h,vector<int>& d){
    d[u]=h;
    for(auto v:adj[u]){
        if(v!=par) dfs(v,u,h+1,d);
    }
}

int main()
{
fastio;
    int n;cin>>n;
    adj.assign(n,vector<int>());
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> d1(n),d2(n);
    // find farthest node A from any random node(say node-0)
    dfs(0,-1,0,d1);
    int a=max_element(all(d1))-d1.begin();
    dfs(a,-1,0,d1); // now d1[v] is distance of node v from a
    int b=max_element(all(d1))-d1.begin();
    dfs(b,-1,0,d2); // d2[v] is distance of node v from b

    vector<int> cnt(n+1,0); 
    // cnt[i] is the no. of nodes v s.t. max_dist(v)=i
    // Lemma:  The vertex farthest from any given vertex v must be one of the endpoints of any diameter of the tree.
    for(int v=0;v<n;v++){
        cnt[max(d1[v],d2[v])]++;
    }
    partial_sum(all(cnt),cnt.begin()); // build prefix 
    // now cnt[i] is no. of nodes v s.t. max_dist(v)<=i
    // all non-isolated vertices form a single CC while others are compltely isolated
    for(int k=1;k<=n;k++){
        cout<<min(cnt[k-1]+1,n)<<" ";
    }
    return 0;
}