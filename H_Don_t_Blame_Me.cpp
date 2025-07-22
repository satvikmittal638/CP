#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
ll MOD=1e9+7;
    int tt;cin>>tt;
    while(tt--){
       int n,k;cin>>n>>k;
       vector<int> a(n);for(auto &i:a) cin>>i;

       vector<vector<ll>> dp(n+1,vector<ll>(1<<6,0ll));// dp[i][j] denotes no. of subsequences from first i elts with &val=j
       for(int i=1;i<=n;i++){
        for(int j=0;j<(1<<6);j++) {
            // extend the previous subsequence by including a[i]
            dp[i][a[i-1]&j]+=dp[i-1][j];
            dp[i][a[i-1]&j]%=MOD;

            // don't extend the prvs subsequence(ignore a[i])
            dp[i][j]+=dp[i-1][j];
            dp[i][j]%=MOD;

        }
            // start a new subsequence from a[i]
            dp[i][a[i-1]]+=1;
            dp[i][a[i-1]]%=MOD;

       }
       ll ans=0ll;
       for(int x=0;x<(1<<6);x++){
        if(__builtin_popcount(x)==k){
            ans+=dp[n][x];
            ans%=MOD;
        }
       }
       cout<<ans<<"\n";
       
    }
    return 0;
}