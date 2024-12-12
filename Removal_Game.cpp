#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<long long> x(n);for(auto &i:x) cin>>i;
    long long dp[n+1][n+1][2];
    // vector<vector<long long> > dp1(n+1,vector<long long>(n+1,0)),dp2(n+1,vector<long long>(n+1,0));
    long long mx=LLONG_MIN;
    // last row and col initialises to 0
    for(int i=0;i<=n;i++){
        dp[0][i][0]=dp[0][i][1]=dp[i][n][0]=dp[i][n][1]=0;
    }
  
    bool p=0;
    for(int f=0;f<n;f++){
       for(int b=n-1;b>=0;b--){
        if(f<=b){
            // choose front or back and then get maximum ans of both ways
            dp[f][b][p]=max(dp[f+1][b][p]+x[f],dp[f][b+1][p]+x[b]);
            mx=max(mx,dp[f][b][0]);   
        }
        // else{
        //     dp[f][b]=dp[f-1][b];
        // }
        p=!p;
       }
    }
    cout<<mx;
    return 0;
}