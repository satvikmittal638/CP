#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int MOD=1e9+7;
int main()
{
fastio;
    int n,k;cin>>n>>k;
    vector<int> a(n);for(auto &i:a) cin>>i;
    int dp[2][k+1];
    // dp[i][j] is no. of ways to distribute j candies amongst children a[i,n-1]
    memset(dp,0,sizeof(dp)); // other dp[n][j]=0 since no way possible
    dp[n&1][0]=1; // empty children
    
    int p[k+1];
    // compute for base case
    p[0]=dp[n&1][0];
    for(int z=1;z<=k;z++) p[z]=p[z-1]+dp[n&1][z];

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=k;j++){
            // give p candies to i-th child
            // for(int p=0;p<=min(a[i],j);p++){
            //     dp[i][j]+=dp[i+1][j-p];
            // }
            int l=j-min(a[i],j),r=j;
            dp[i&1][j]=p[r]-(l>0?p[l-1]:0);
            dp[i&1][j]+=MOD;
            dp[i&1][j]%=MOD;
        }
        // take prefix sum
        memset(p,0,sizeof(p));
        p[0]=dp[i&1][0];
        for(int z=1;z<=k;z++){
            p[z]=p[z-1]+dp[i&1][z];
            p[z]%=MOD;
        }
    }
    cout<<dp[0][k];
    return 0;
}