#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,c;cin>>n>>a>>b>>c;
    // dp[i][j] denotes maxm no. of ribbon pieces obtained 
    //after cutting a ribbon of length i with last cut denoted by j
    //j=0,1,2 for a,b,c
    int dp[n+1][3];
    // no ribbon of 0 length can be formed
    dp[0][0]=dp[0][1]=dp[0][2]=0;
    // -inf rejects out impossible cuts(unreachable states)(don't use 0 here !! since it denotes a reachable state)
    for(int i=1;i<=n;i++){
        dp[i][0]=i>=a?(1+max({dp[i-a][0],dp[i-a][1],dp[i-a][2]})):INT_MIN;
        dp[i][1]=i>=b?(1+max({dp[i-b][0],dp[i-b][1],dp[i-b][2]})):INT_MIN;
        dp[i][2]=i>=c?(1+max({dp[i-c][0],dp[i-c][1],dp[i-c][2]})):INT_MIN;

    }
    cout<<max({dp[n][0],dp[n][1],dp[n][2]});
    return 0;
}