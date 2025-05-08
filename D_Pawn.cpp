#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
    const int INF=1e9;
fastio;
    int n,m,k;cin>>n>>m>>k;
    vector<vector<int>> a(n+1,vector<int>(m+1,0));
    // fill in bottom to top manner(lowest row is now at top) so we 
    // start from (1,1) to go (m,n)
    for(int i=n;i>=1;i--){
        for(int j=1;j<=m;j++){
            char c;cin>>c;
            a[i][j]=c-'0';
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    int dp[105][105][15];
    for(int i=0;i<105;i++){
        for(int j=0;j<105;j++){
            for(int k=0;k<15;k++){
                dp[i][j][k]=-INF;
            }
        }
    }
    // NOTE:y is for row and x is for col so a[y][x] is value at cell (x,y)
    // base case-> bottom row
    for(int x=1;x<=m;x++){
        dp[x][1][(a[1][x])%(k+1)]=a[1][x];
    }
    for(int y=1;y<n;y++){
        for(int x=1;x<=m;x++){
            for(int z=0;z<=k;z++){
                if(dp[x][y][z]>=0){
                    // up and right
                    if(x + 1 <= m) { 
                        dp[x+1][y+1][(z+a[y+1][x+1])%(k+1)] = 
                            max(dp[x+1][y+1][(z+a[y+1][x+1])%(k+1)], dp[x][y][z] + a[y+1][x+1]);
                    }
                    // up and left
                    if(x - 1 >= 1) { 
                        dp[x-1][y+1][(z+a[y+1][x-1])%(k+1)] = 
                            max(dp[x-1][y+1][(z+a[y+1][x-1])%(k+1)], dp[x][y][z] + a[y+1][x-1]);
                    }
                }
            }
        }
    }

    // for(int y=1;y<=n;y++){
    //     for(int x=1;x<=m;x++){
    //         for(int z=0;z<=k;z++){
    //             cout<<dp[x][y][z]<<" ";
    //         }
    //         cout<<"\n";
    //     }
    //     cout<<"\n";
    // }
    int ans=-INF;
    int ansx=-1;
    for(int x=1;x<=m;x++){
        if(ans<dp[x][n][0]){
            ans=dp[x][n][0];
            ansx=x;
        }
    }
    int curx=ansx,curMod=0;
    string path;
    for(int y=n-1;y>=1;y--){
        int tgtVal=dp[curx][y+1][curMod]-a[y+1][curx],tgtMod=tgtVal%(k+1);
        if(curx>1 && dp[curx-1][y][tgtMod]==tgtVal) {
            path+='R';
            curx--;
        }
        else {
            path+='L';
            curx++;
        }
        curMod=tgtMod;
    }
    reverse(all(path));
    if(ans<0) ans=-1; // no route found
    cout<<ans<<"\n";
    /*
    curx is the starting cell of the bottom row
    ansx is the ending cell of the topmost row
    */
    if(ans!=-1){
        cout<<curx<<"\n"<<path;
    }
    return 0;
}