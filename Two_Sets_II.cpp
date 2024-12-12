#include <iostream>
#include <vector>
using namespace std;

long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

long long modInverse(long long a, long long mod) {
    return modExp(a, mod - 2, mod);
}

int main() {
    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    
    if (sum % 2 != 0) {
        cout << 0;
        return 0;
    }

    int target = sum / 2;
    vector<vector<long long> > dp(n + 1, vector<long long>(target + 1, 0));
    dp[0][0] = 1; // No numbers used, sum of 0 -> 1 way to achieve this

    // Filling DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            dp[i][j] = dp[i - 1][j]; // Exclude i by default
            if (j >= i) {
                dp[i][j] += dp[i - 1][j - i]; // Include i if possible
                dp[i][j] %= 1000000007; // Apply modulo to keep values manageable
            }
        }
    }

    // Result is half of dp[n][target] because each partition is counted twice
    dp[n][target]*=modInverse(2,1000000007);
    dp[n][target]%=1000000007;
    cout << dp[n][target];
    return 0;
}