#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
using pii=pair<int,int>;

map<pii,vector<pii>> adj;
map<pii,ll> dp;// dp[u] is no. of paths from root S to node u

int main()
{
fastio;
    vector<string> grid;
    string line;

    while (getline(cin, line)) {
        grid.push_back(line);
    }
    int n=grid.size(),m=grid[0].size();

    // for each cell (i,j), pre-compute the nearest splitter or exit below it in the same column j
    vector<vector<pii>> nearestSplitter(n,vector<pii>(m,{-1,-1}));
    
    // base case for last column(exit)
    for(int j=0;j<m;j++){
        nearestSplitter[n-1][j]={n-1,j};
    }
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<m;j++){
            nearestSplitter[i][j]=nearestSplitter[i+1][j];
            if(grid[i+1][j]=='^') nearestSplitter[i][j]={i+1,j};
        }
    }
    // now build a Directed graph
    vector<bool> hasBeam(m,0);
    
    // handle 1st row
    for(int j=0;j<m;j++){
        if(grid[0][j]=='S'){
            hasBeam[j]=1;
            dp[{0,j}]=1;// base case
            adj[{0,j}].push_back(nearestSplitter[0][j]);
            break;
        }
    }
    // handle subsequent rows
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='^'){
                hasBeam[j-1]=1;
                hasBeam[j]=0;
                hasBeam[j+1]=1;
                // connect 
                adj[{i,j}].push_back(nearestSplitter[i][j-1]);
                adj[{i,j}].push_back(nearestSplitter[i][j+1]);
            }
        }
    }
    // level order traversal of the directed graph
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            auto p=make_pair(i,j);
            if(adj.count(p)){
                for(auto &v:adj[p]){
                    dp[v]+=dp[p];// add no. of paths to the child
                }
            }
        }
    }
    ll ans=0ll;
    for(int j=0;j<m;j++){
        ans+=dp[{n-1,j}];
    }
    cout<<ans;
    return 0;
}