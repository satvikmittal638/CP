#include<bits/stdc++.h>
using namespace std;
int main()
{
    const long long MOD=1000000007;
    int n,k;cin>>n>>k;
    vector<long long> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    /*
    dp[i][j] denotes number of ways for first i children to
    distribute a total of j candies amongst themselves
    */
    vector<vector<long long> > dp(n+1,vector<long long>(k+1,0));
    dp[0][0]=1;// base case
    // dp[i][0]=1, dp[0][j]=0-> base cases
    // first row initialisation
    for(int j=1;j<=k;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        dp[i][0]=1;
    }
    
    for(int i=1;i<=n;i++){
        // TODO:Get the WA TC by stress testing the code against the given solution
        vector<long long> prefix(k+1,0); // for dp[i-1][j] where j is variable
        prefix[0]=dp[i-1][0];
        for (int j = 1; j <= k; j++) {
            prefix[j] = (prefix[j - 1] + dp[i - 1][j]) % MOD;
        }
        
        for(int j=0;j<=k;j++){
            // try giving l candies to the ith child
            // for(int l=0;l<=a[i];l++){
                if(j-a[i]>=1) {
                    dp[i][j]=(prefix[j]-prefix[j-a[i]-1]);
                    dp[i][j]%=MOD;
                }else{
                    dp[i][j]=prefix[j];
                }
            // }
        }
    }
    cout<<dp[n][k];
    
    return 0;
}