#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n;cin>>n;
    vector<int> c(n);
    for(auto &i:c) cin>>i;
    vector<vector<int>> dp(n,vector<int>(n,0));
    // base case
    for(int i=0;i<n;i++) dp[i][i]=1;
    for(int l=n-1;l>=0;l--){
        for(int r=l+1;r<n;r++){
            dp[l][r]=1+dp[l+1][r];
            if(l+2<n && c[l]==c[l+1])dp[l][r]=min(dp[l][r],1+dp[l+2][r]);
            for(int k=l+2;k<=r;k++){
                dp[l][r]=min(dp[l][r],dp[l+1][k-1]+dp[k+1][r]);
            }
        }
    }
    cout<<dp[0][n-1];

    return 0;
}