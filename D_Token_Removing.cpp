#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5001;
int dp[MAXN][MAXN];

void precompute(int mod) {
    dp[0][0] = 1;
    for (int i = 1; i < MAXN; i++) {
        for (int j = 0; j <= i; j++) {
            // Case 1: don't remove any token at position i
            dp[i][j] = dp[i - 1][j];
            
            // Case 2: remove a token at position i
            if (j > 0) {
                dp[i][j] = (dp[i][j] + 1LL * dp[i - 1][j - 1] * (i - j + 1)) % mod;
            }
        }
    }
}

int solve(int n, int mod) {
    int result = 0;
    for (int j = 0; j <= n; j++) {
        result = (result + dp[n][j]) % mod;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    // Read all inputs first to get the maximum m for precomputing mod-safe
    vector<pair<int, int>> queries(t);
    int max_n = 0;
    for (int i = 0; i < t; i++) {
        cin >> queries[i].first >> queries[i].second;
        max_n = max(max_n, queries[i].first);
    }

    for (int i = 0; i < t; i++) {
        int n = queries[i].first;
        int mod = queries[i].second;

        // Recompute dp for this mod value
        precompute(mod);

        cout << solve(n, mod) << '\n';
    }

    return 0;
}