#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    const ll INF=1e18;
    int tt;cin>>tt;
    while(tt--){
       int n,a,b;cin>>n>>a>>b;
       string s;cin>>s;
       /*
    Let dp[i][1] denote minm cost if there is a pipe of height 1 at i
    Let dp[i][2] denote minm cost if there is a pipe of height 2 at i
    for road of length i from start(0)
       */
       vector<vector<ll>> dp(n+1,vector<ll>(3,INF));
       dp[0][1]=(ll)b;
       for(int i=1;i<=n;i++){
        if(s[i-1]=='0'){
            dp[i][1]=min(dp[i][1],dp[i-1][1]+a+b);
            dp[i][1]=min(dp[i][1],dp[i-1][2]+2*a+b);
            
            
            dp[i][2]=min(dp[i][2],dp[i-1][1]+2*(a+b));
            dp[i][2]=min(dp[i][2],dp[i-1][2]+a+2*b);

        }
        else{
            dp[i][2]=min(dp[i][2],dp[i-1][2]+a+2*b);
        }
       }
       cout<<dp[n][1]<<"\n";
    }
    return 0;
}