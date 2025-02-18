#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
    const int INF=1e9;
fastio;
    int tt;cin>>tt;
    while(tt--){
       string a,b,c;cin>>a>>b>>c;
       int n=a.length(),m=b.length();
       vector<vector<int>> dp(n+1,vector<int>(m+1,INF));
       // Base cases
       dp[0][0]=0;
        for (int i = 0; i < n; i++) {
            dp[i + 1][0] = dp[i][0] + (a[i] !=  c[i]);
        }
        for (int j = 0; j < m; j++) {
            dp[0][j + 1] = dp[0][j] + (b[j] !=  c[j]);
        }
       for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=min(dp[i-1][j]+(a[i-1]!=c[i+j-1]),dp[i][j-1]+(b[j-1]!=c[i+j-1]));
        }
       }
       cout<<dp[n][m]<<"\n";
       
    }
    return 0;
}