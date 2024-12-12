#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<string> grid(n);
    for(auto &i:grid) cin>>i;

    // dp[i][j]->no of ways to reach (i,j) from (0,0)
    vector<vector<long long> > dp(n,vector<long long>(n,0));
    // initialise 1st row and 1st col
    int i=0;
    // no way to reach if an obstacle came in b/w
    while(i<n && grid[i][0]!='*') dp[i++][0]=1;
    i=0;
    while(i<n && grid[0][i]!='*') dp[0][i++]=1;
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(grid[i][j]=='.'){
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1000000007;
            }
        }
    }
    cout<<dp[n-1][n-1];
    
    return 0;
}