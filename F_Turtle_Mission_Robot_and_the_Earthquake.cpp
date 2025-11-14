#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int INF=1e9;
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,m;cin>>n>>m;
       vector<vector<int>> a(n,vector<int>(m,0)),time(n,vector<int>(m,INF));
       for(int i=0;i<n;i++)for(int j=0;j<m;j++) cin>>a[i][j];
       // run a BFS on grid
       queue<pair<int,int>> q;
       q.emplace(0,0);
       time[0][0]=0;
       while(q.size()){
        auto [x,y]=q.front();
        q.pop();
        // make a right move(u also move down wrt grid)
        if(y<m-1 && a[(x+1)%n][y+1]==0 && time[(x+1)%n][y+1]>=INF){
            time[(x+1)%n][y+1]=time[x][y]+1;
            q.emplace((x+1)%n,y+1);
        }
        // make a down move(u also move 1 more step down wrt grid)
        if(a[(x+1)%n][y]==0 && a[(x+2)%n][y]==0 && time[(x+2)%n][y]>=INF){
            time[(x+2)%n][y]=time[x][y]+1;
            q.emplace((x+2)%n,y);
        }
        // moving up(u move down 1 step wrt grid)->equivalent to waiting->never a part while minimizing time
       }
    
       int ans=INF;
       for(int i=0;i<n;i++){
        int b=time[i][m-1],c=(i-(b%n)+n)%n; // reach 2nd last column
        if(b>=INF) continue;
        // now chase the moving end
        ans=min(ans,b+min(c+1,n-1-c));
       }
       if(ans>=INF) ans=-1;
       cout<<ans<<'\n';
    }
    return 0;
}