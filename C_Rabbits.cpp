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
       string s;cin>>s;
       s=' '+s;

       // dp[i][0]: valid for [1,i], rabbit at i looks left
       // dp[i][1]: valid for [1,i], rabbit at i looks right
       // dp[i][2]: valid for [1,i], flower at i (calm, no rabbit at i-1 looks at it)
       // dp[i][3]: valid for [1,i], flower at i (threatened by rabbit at i-1)
       vector<vector<bool>> dp(n+1,vector<bool>(4,0));

       // base
       if(s[1]=='0'){
        dp[1][0]=1;
        dp[1][1]=1;
       }
       else{
        dp[1][2]=1;
       }

       for(int i=2;i<=n;i++){
         if (s[i] == '0') {
            
            if (dp[i-1][0] || dp[i-1][1]) {dp[i][0] = dp[i][1]=1;}
            if (dp[i-1][3]) dp[i][0] = 1;
            if (dp[i-1][2]) dp[i][1] = 1;

         } else { 
            if (dp[i-1][0] || dp[i-1][2]) dp[i][2] = 1;
            if (dp[i-1][1]) dp[i][3] = 1;
         }
       }
       cout<<((dp[n][0] || dp[n][1] || dp[n][2]) ? "YES" : "NO") << '\n';
    }
    return 0;
}