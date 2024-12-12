#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h1(n + 1), h2(n + 1);
    for (int i = 1; i <= n; i++) cin >> h1[i];
    for (int i = 1; i <= n; i++) cin >> h2[i];

    /*
    dp[i][1] -> max height last choosing h1[i-1]
    dp[i][2] -> max height last choosing h2[i-1]
    dp[i][3] -> max height last w/o choosing any of h1[i] and h2[i]
    case of taking both h1[i-1] and h2[i-1] is already covered in 1 and 2
    */
    // long long dp[n + 1][4];
    long long dp1=0,dp2=0,dp3=0;
    long long ndp1,ndp2,ndp3;
    // dp[0][1]=dp[0][2]=dp[0][3]=0;
    // optimized dp
    for (int i = 1; i <= n; i++) {
        // dp[i][1]=h1[i]+max(dp[i-1][2],dp[i-1][3]);
        // dp[i][2]=h2[i]+max(dp[i-1][1],dp[i-1][3]);
        // dp[i][3]=max(dp[i-1][1],dp[i-1][2]);
        ndp1=h1[i]+max(dp2,dp3);
        ndp2=h2[i]+max(dp1,dp3);
        ndp3=max(dp1,dp2);
        dp1=ndp1;
        dp2=ndp2;
        dp3=ndp3;
    }

    // cout << max({ dp[n][1], dp[n][2],dp[n][3]});
    cout<<max({dp1,dp2,dp3});
    return 0;
}