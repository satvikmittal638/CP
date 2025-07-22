#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n;cin>>n;
    vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>()); // stores neighbour as well as index of the edge(as per input)
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;u--;v--;
        adj[u].emplace_back(v,i);
        adj[v].emplace_back(u,i);
    }
    int u=-1;
    for(int i=0;i<n;i++){
        if(adj[i].size()>=3){
            u=i;
            break;
        }
    }
    // max degree=2 -> straight chain like structure-> mex=n-1 always
    if(u==-1){
        for(int i=0;i<n-1;i++) cout<<i<<"\n";
        return 0;
    }
    vector<int> ans(n-1,-1);
    ans[adj[u][0].second]=0;
    ans[adj[u][1].second]=1;
    ans[adj[u][2].second]=2;
    int x=3;
    for(int i=0;i<n-1;i++){
        if(ans[i]==-1) ans[i]=x++;
    }
    for(auto e:ans) cout<<e<<"\n";
    return 0;
}