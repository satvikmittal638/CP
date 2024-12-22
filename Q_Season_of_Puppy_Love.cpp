#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int solve(int n) {
    // dp[i] will store the number of valid mappings for i profiles
    long long dp[n + 1];
    dp[0] = 1;  // Base case: 1 way to map 0 profiles (empty set)
    
    for (int i = 1; i <= n; i++) {
        dp[i] = (dp[i - 1] * i) % MOD;  // Recurrence relation
    }
    
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    
    // Output the result
    cout << solve(n) << endl;
    return 0;
}