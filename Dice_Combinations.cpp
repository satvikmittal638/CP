#include<iostream>
#include<vector>
using namespace std;

int main() {
    const long long MOD = 1e9 + 7;
    int n;
    cin >> n;

    vector<long long> dp(n + 1, 0); // dp[i]: number of ways to make sum i
    dp[0] = 1; // Base case: 1 way to make sum 0 (by doing nothing)

    // Fill dp for sums from 1 to n
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }

    cout << dp[n] << endl; // Output the number of ways to make sum n
    return 0;
}