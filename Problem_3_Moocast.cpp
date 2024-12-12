#include<bits/stdc++.h>
using namespace std;

// checks if a given cowj(x,y) is in range of walkie-talkie of originating cowi(c_x,c_y)
bool inRange(int c_x,int c_y,int x,int y,int p){
    return (x-c_x)*(x-c_x) + (y-c_y)*(y-c_y) <= p*p;
}

void dfs(vector<vector<int>>& adjLst,vector<bool>& visited, int start,int &len){
    // visit start
    len++; 
    visited[start]=1;
    for(auto node:adjLst[start]){
        if(!visited[node]){
            dfs(adjLst,visited,node,len);
        }
    }
}

int main()
{
    //for USACO grading servers
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    //
    int n;cin>>n;
    vector<int> x(n),y(n),p(n);
    for (int i = 0; i < n; i++)
    {
        cin>>x[i]>>y[i]>>p[i];
    }
    // traverse all possible pairs of cows to build a graph(adjacency list)
    // adjLst[i]-> contains neighbours to which signal can be sent by cow i
    vector<vector<int>> adjLst(n,vector<int>());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // don't include self
            if(i!=j){
                if(inRange(x[i],y[i],x[j],y[j],p[i])){
                    adjLst[i].emplace_back(j);
                }
            }
        }
    }
    
    // perform dfs starting from each vertex and get the maxm length dfs
    int ans=0;
    for(int i=0;i<n;i++){
        int len=0;
        vector<bool> visited(n,0);
        dfs(adjLst,visited,i,len); // updates the value of len
        ans=max(ans,len);//update the ans
    }
    cout<<ans;
    return 0;
}