#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MOD = 1e9 + 7;

int main() {
    fastio;
    string s;
    cin >> s;
    int n = s.length();

    vector<int> prefb(n, 0), dp(n, 0), pref_dp(n, 0);

    for (int i = 0; i < n; i++) {
        prefb[i] = (s[i] == 'b');
        dp[i] = (s[i] == 'a');
        if (i > 0) prefb[i] += prefb[i - 1];
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] != 'a') continue;

        // BS for the largest j such that prefb[i] - prefb[j] > 0
        int lo = 0, hi = i - 1, validJ = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (prefb[i] - prefb[mid] > 0) {
                validJ = mid; 
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        // Use prefix sum to calculate sum of dp[j] for all valid j
        if (validJ != -1) {
            int sum = pref_dp[validJ];
            dp[i] = (dp[i] + sum) % MOD;
        }

        pref_dp[i] = dp[i];
        if (i > 0) pref_dp[i] = (pref_dp[i] + pref_dp[i - 1]) % MOD;

        ans = (ans + dp[i]) % MOD;
    }

    cout << ans;
    return 0;
}