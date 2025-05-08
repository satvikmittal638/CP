#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    const int INF=1e9;
    int n;cin>>n;
    vector<int> h(n+1);
    for(int i=1;i<=n;i++) cin>>h[i];
    vector<vector<int>> dp(n+1,vector<int>(n+1,INF));
    dp[0][0]=0;
    vector<int> p_min(n+1,0); // base cased for j=0
    for(int j=1;j<=(n+1)/2;j++){
        for(int i=2*j-1;i<=n;i++){
            // Case 1: previous peak not at i-2 so
            // use prefix min of dp[i_var][j-1]
            if((i-2)>=1)dp[i][j]=min(dp[i][j],p_min[i-2]);
            else dp[i][j]=0;

            // Compute cost to make house at peak i
            // check left hill
            if(i>1 && h[i]<=h[i-1]) dp[i][j]+=h[i-1]-h[i]+1;
            // check right hill
            if(i<n && h[i]<=h[i+1]) dp[i][j]+=h[i+1]-h[i]+1;
            
            if((i-2)<1) continue;
            // Case 2:previous peak at i-2, so handle overlapping adjustments made
           // Previous peak at prev_hill (i-2) would have made h[i-1] <= h[prev_hill] - 1
           int prev_hill = i - 2;
            int current_cost = 0;
           int new_h_prev = h[prev_hill];
           int new_h_mid = min(h[i - 1], new_h_prev - 1);
           if (new_h_mid >= h[i]) current_cost += new_h_mid - h[i] + 1;
           if (i < n && h[i] <= h[i + 1]) current_cost += h[i + 1] - h[i] + 1;
           current_cost += dp[prev_hill][j - 1];
           dp[i][j] = min(dp[i][j], current_cost);
        }
        p_min[0]=INF;
        // build prefix minm for next iteration of j
        for(int i=1;i<=n;i++){
            p_min[i]=min(p_min[i-1],dp[i][j]);
        }
    }
    for(int k=1;k<=(n+1)/2;k++){
        // last house maybe built anywhere
        int ans=INF;
        for(int i=2*k-1;i<=n;i++){
            ans=min(ans,dp[i][k]);
        }
        cout<<ans<<" ";
    }
    return 0;
}