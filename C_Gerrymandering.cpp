#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<string> s(2);for(auto &i:s) cin>>i;
       // dp[i][j] denotes maxm districts won for first i districts with ith col starting with situation j
       /*
       j=0-> all rows filled upto column i
       j=1-> all rows filled upto column i and 1st row has 1 extra cell filled
       j=2-> all rows filled upto column i and 2nd row has 1 extra cell filled
       */
       vector<vector<int>> dp(n+1,vector<int>(3,-1));
       dp[0][0]=0; // base case
       for(int i=0;i<n;i++){
        int vot;
        // from dp[i][0]
        vot=s[0][i]=='A'+s[1][i]=='A'+s[]
        dp[i+1][2]=max(dp[i+1][2],dp[i][0]+vot);
        dp[i+1][1]=max(dp[i+1][1],dp[i][0]+vot);
        dp[i+3][0]=max(dp[i+3][0],dp[i][0]+vot);
        
        // from dp[i][1]
        dp[i+2][0]=max(dp[i+2][0],dp[i][1]+vot);
        dp[i+3][1]=max(dp[i+3][1],dp[i][1]+vot);
        
        // from dp[i][2]
        dp[i+2][0]=max(dp[i+2][0],dp[i][2]+vot);
        dp[i+3][2]=max(dp[i+3][2],dp[i][2]+vot);

       }
       cout<<dp[n][0]<<"\n";
    }
    return 0;