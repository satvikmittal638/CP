#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;

int cntSeq(int N, vector<int>& rollMax) {
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(6, vector<int>(51, 0)));
    
    // Base case: At step 1, we can place any number 1-6 exactly once
    for (int j = 0; j < 6; j++) {
        dp[1][j][1] = 1;
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 6; j++) {  // Last number used
            for (int k = 1; k <= rollMax[j]; k++) {  // Consecutive count of j
                if (dp[i][j][k] == 0) continue;

                // Case 1: Continue using same number (if within limit)
                if (k < rollMax[j]) {
                    dp[i + 1][j][k + 1] = (dp[i + 1][j][k + 1] + dp[i][j][k]) % MOD;
                }

                // Case 2: Switch to a different number
                for (int new_j = 0; new_j < 6; new_j++) {
                    if (new_j == j) continue; // Skip same number
                    dp[i + 1][new_j][1] = (dp[i + 1][new_j][1] + dp[i][j][k]) % MOD;
                }
            }
        }
    }

    // Sum up valid sequences of length N
    int res = 0;
    for (int j = 0; j < 6; j++) {
        for (int k = 1; k <= rollMax[j]; k++) {
            res = (res + dp[N][j][k]) % MOD;
        }
    }

    return res;
}

int main() {
    int N;
    cin >> N;
    vector<int> rollMax(6);
    for (int i = 0; i < 6; i++) cin >> rollMax[i];

    cout << cntSeq(N, rollMax) << "\n";
    return 0;
}