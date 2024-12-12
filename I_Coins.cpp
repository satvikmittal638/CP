#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<double> p(n+1);
    for(int i=1;i<=n;i++) cin>>p[i];
    /*
    Let dp[i][j] denotes the probability of getting exactly j heads 
    by using the first i coins out of n
    */
   vector<vector<double>> dp(n+1,vector<double>(n+1));
   // Base case
   dp[0][0]=1;
   for(int i=1;i<=n;i++){
    dp[0][i]=0; // use 0 coins to make non-0 number of heads--> never possible
   }
   for(int i=1;i<=n;i++){
    for(int j=0;j<=n;j++){
        /*
        make ith coin tail if we already had j heads
        make ith coin head if we had (j-1) heads
        */
        dp[i][j]=dp[i-1][j]*(1-p[i]) + (j>=1?(dp[i-1][j-1]*p[i]):0);
    }
   }
    // now find sum for dp[n][j] where floor(n/2)<j<=n
    double ans=0;
    for(int j=(n/2)+1;j<=n;j++){
        ans+=dp[n][j];
    }
    cout << fixed << setprecision(10) << ans ;
    return 0;
}