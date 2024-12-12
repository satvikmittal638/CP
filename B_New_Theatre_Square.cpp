#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,m,x,y;cin>>n>>m>>x>>y;
       vector<vector<bool>> grid(n,vector<bool>(m));
       int cnt_0=0,cnt_1=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;cin>>c;
            if(c=='.') {grid[i][j]=0;cnt_0++;}
            else {grid[i][j]=1;cnt_1++;}
        }
       }
       long long cost=0;
       // use 1X1 only
       if(y>=2*x) cost=cnt_0*x;
       else{
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // a place for 2X2 tile found :)
                if(j<m-1 && grid[i][j]==0 && grid[i][j+1]==0){
                    cost+=y;
                    grid[i][j]=grid[i][j+1]=1;
                }
                if(grid[i][j]==0 && (grid[i][j+1]==1 || j==m-1)) cost+=x;
            }
        }
       }
       cout<<cost<<"\n";

    }
    return 0;
}