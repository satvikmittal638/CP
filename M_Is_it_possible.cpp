#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        int n = s.size();

        // dp[i] will store the number of valid partitions for the prefix s[0..i-1]
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // base case: one way to partition an empty string

        unordered_map<char, vector<int>> last_pos; // stores last positions of each character

        for (int i = 1; i <= n; ++i) {
            char c = s[i - 1];
            
            // Start by inheriting the previous dp value
            dp[i] = dp[i - 1];

            // If we've seen the character before and can form an interesting substring
            if (last_pos.find(c) != last_pos.end()) {
                for (int j : last_pos[c]) {
                    if (i - j > 1) {
                        dp[i] = (dp[i] + dp[j]) % MOD;
                    }
                }
            }

            // Record the current position of character c
            last_pos[c].push_back(i);
        }

        // The answer for the current test case is dp[n], number of partitions for the whole string
        cout << dp[n] << "\n";
    }

    return 0;
}