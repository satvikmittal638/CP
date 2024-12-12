#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,p,q,r;cin>>n>>p>>q>>r;
    vector<long long> a(n);
    for(auto &i:a) cin>>i;
    long long dp[n][3];
    /*
    dp[i][0] denotes maximum value of p*a[i]
    dp[i][1] denotes maximum value of p*a[j]+q*a[i] for some j<=i
    dp[i][2] denotes maximum value of p*a[j]+q*a[k]+r*a[i] for some j<=k<=i

    */
    //base case
    dp[0][0]=p*a[0];
    dp[0][1]=dp[0][0]+q*a[0];
    dp[0][2]=dp[0][1]+r*a[0];
    for(int i=1;i<n;i++){
        dp[i][0]=max(dp[i-1][0],p*a[i]);
        dp[i][1]=max(dp[i-1][1],dp[i][0]+q*a[i]);
        dp[i][2]=max(dp[i-1][2],dp[i][1]+r*a[i]);
    }
    cout<<dp[n-1][2];
    return 0;
}