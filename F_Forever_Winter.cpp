#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,m;cin>>n>>m;
       vector<vector<int>> adj(n+1,vector<int>());
       while(m--){
        int u,v;cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
       }
       map<int,int> freq;
       for(int v=1;v<=n;v++){
        freq[adj[v].size()]++;
       }
       int x,y,xy;
       /*
       freq will have only 3 types of degrees-1,x,y+1
       1 degree->xy vertices
       x degree-> 1 vertex
       y+1 degree-> x vertices
       */ 
       for(auto p:freq){
        if(p.second==1) x=p.first;
        else if(p.first==1) xy=p.second;
        else y=p.first-1;
       }
       // if x=y+1, freq of either of x or y+1 is counted as 0
       if(freq[x]==0 || freq[y+1]==0){
        y=(sqrt(1+4*xy)-1)/2; // solve quadratic
        x=y+1;
       }
       cout<<x<<" "<<y<<"\n";

    }
    return 0;
}