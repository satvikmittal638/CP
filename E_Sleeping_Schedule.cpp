#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n,h,l,r;cin>>n>>h>>l>>r;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> p(n+1,0);
    partial_sum(all(a),p.begin());
    // dp[i][j] is ans for [1,i] s.t. we did -1 j times (0<=j<=i)
    vector<vector<int>> dp(n+1,vector<int>(n+1,0)); 
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            int t=(p[i]-j)%h;
            dp[i][j]=max(dp[i-1][j],(j>0?dp[i-1][j-1]:INT_MIN))+ (l<=t && t<=r);
        }
    }
    int ans=0;
    for(int j=0;j<=n;j++){
        ans=max(ans,dp[n][j]);
    }
    cout<<ans;
    return 0;
}