#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
    // for CF-submission only
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
fastio;
    const int INF=1e9;
    int n,a,b;cin>>n>>a>>b;
    //h[0]=0 is required (somewhat like an edge case)
    vector<int> h(n+1,0);for(int i=1;i<=n;i++)cin>>h[i];
    /*
    dp[i][j][0] is ans for [1,i] with j units of R used and i-th fence as R
    dp[i][j][1] is ans for [1,i] with j units of R used and i-th fence as G
    */
    int dp[n+1][a+1][2];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=a;j++){
            for(int k=0;k<2;k++){
                dp[i][j][k]=INF;
            }
        }
    }
    dp[0][0][0]=0;
    int cur_sum=0;
    for(int i=1;i<=n;i++){
        cur_sum+=h[i];
        for(int r=0;r<=a;r++){
            int g=cur_sum-r;
            if(r>=h[i]) dp[i][r][0]=min(dp[i-1][r-h[i]][0],dp[i-1][r-h[i]][1]+min(h[i],h[i-1]));
            if(g<=b)dp[i][r][1]=min(dp[i-1][r][0]+min(h[i],h[i-1]),dp[i-1][r][1]);
        }
    }
    int ans=INF;
    for(int i=0;i<=a;i++){
        ans=min({ans,dp[n][i][0],dp[n][i][1]});
    }
    cout<<(ans>=INF?-1:ans);
    return 0;
}