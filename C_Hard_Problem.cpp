#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

int main() {
    fastio;
    int n;
    cin >> n;
    vector<ll> c(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> c[i];
    vector<string> s(n + 1);
    for (int i = 1; i <= n; i++) cin >> s[i];
    
    /*
    dp[i][0] denotes the minm cost till first i string if ith string is not reversed
    dp[i][1] denotes the minm cost till first i string if ith string is reversed
    */
    vector<vector<ll>> dp(n + 1, vector<ll>(2, LLONG_MAX));
    
    dp[1][0] = 0ll;         // Don't reverse the first string
    dp[1][1] = c[1];        // Reverse the first string
    
    for (int i = 2; i <= n; i++) {
        string rev_curS = s[i];
        reverse(all(rev_curS));
        string rev_prevS = s[i - 1];
        reverse(all(rev_prevS));
        
        // Prevent adding costs to impossible states
        // Reverse the current string
        if (dp[i - 1][0] != LLONG_MAX && rev_curS >= s[i - 1]) {
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + c[i]);
        }
        if (dp[i - 1][1] != LLONG_MAX && rev_curS >= rev_prevS) {
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
        }
        
        // Don't reverse the current string
        if (dp[i - 1][0] != LLONG_MAX && s[i] >= s[i - 1]) {
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        }
        if (dp[i - 1][1] != LLONG_MAX && s[i] >= rev_prevS) {
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        }
    }
    
    ll ans = min(dp[n][0], dp[n][1]);
    if (ans == LLONG_MAX) cout << "-1\n";
    else cout << ans << "\n";
    return 0;
}