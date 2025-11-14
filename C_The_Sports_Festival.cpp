#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll INF=1e18;
int main()
{
fastio;
    int n;cin>>n;
    vector<ll> s(n);for(auto &i:s) cin>>i;
    sort(all(s));
    vector<vector<ll>> dp(n,vector<ll>(n,INF));
    for(int i=0;i<n;i++) dp[i][i]=0;
    // traverse in increasing lengths
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            dp[l][r] = s[r] - s[l] + min(dp[l+1][r], dp[l][r-1]);
        }
    }
    cout<<dp[0][n-1];
    return 0;
}