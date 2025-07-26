#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    const int M=998244353;
    int tt;cin>>tt;
    while(tt--){
       int n,m,d;cin>>n>>m>>d;
       vector<string> grid(n);for(auto &i:grid) cin>>i;
       ll dp[n+1][m+1][2];
       memset(dp,0ll,sizeof(dp));
       for(int i=0;i<m;i++){
        if(grid[0][i]=='X')
            dp[0][i][0]=1;
            dp[0][i][1]=1;
       }
       for(int j=m-1;j>=0;j--){
            for(int i=0;i<n;i++){
            for(int k=0;k<m;k++){
                // go from level below
                if(grid[i][j]=='X' && (i-k)*(i-k)<=d*d-1)
                    dp[i][j][0]+=dp[k][j-1][0]+dp[k][j-1][1];
                
                // go from same level
                if(grid[i][j]=='X' && abs(i-k)<=d){
                    dp[i][j][1]+=dp[k][j][0];
                }
                dp[i][j][0]%=M;
                dp[i][j][1]%=M;
            }
        }
       }
       ll ans=0ll;
       for(int i=0;i<m;i++){
        if(grid[n][m]=='X'){
            ans+=dp[n][i][0]+dp[n][i][1];
            ans%=M;
        }
       }
       cout<<ans<<"\n";

    }
    return 0;
}