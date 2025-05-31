#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n,m;cin>>n>>m;
    vector<pair<int,int>> v(n);
    vector<int> cost(n);
    for(int i=0;i<n;i++){
        cin>>cost[i];
        v[i]={cost[i],i};
    }
    vector<vector<int>> adj(n,vector<int>());
    while(m--){
        int x,y;cin>>x>>y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    sort(rall(v));
    vector<bool> avlble(n,1);
    ll ans=0ll;
    // remove the vertex in decreasing order of their values
    for(int i=0;i<n;i++){
        // break all edges of this node
        for(auto u:adj[v[i].second]){
            ans+=cost[u]*avlble[u];
        }
        avlble[v[i].second]=0;
    }
    cout<<ans;

    return 0;
}