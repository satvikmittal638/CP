#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

int main() {
    fastio;
    const int MAX = 1e4 + 10;
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int S = accumulate(a.begin() + 1, a.end(), 0);
    
    vector<vector<int>> dp(n + 1, vector<int>(MAX, MAX));
    vector<vector<int>> f(n + 1, vector<int>(MAX, 0)); // f tracks the maximum sum of a's
    
    dp[0][0] = 0;
    f[0][0] = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < MAX; j++) {
            // Not taking the i-th bottle
            dp[i][j] = dp[i-1][j];
            f[i][j] = f[i-1][j];
            
            // Taking the i-th bottle if possible
            if (j >= b[i]) {
                if (dp[i-1][j - b[i]] + 1 < dp[i][j] || 
                    (dp[i-1][j - b[i]] + 1 == dp[i][j] && f[i-1][j - b[i]] + a[i] > f[i][j])) {
                    dp[i][j] = dp[i-1][j - b[i]] + 1;
                    f[i][j] = f[i-1][j - b[i]] + a[i];
                }
            }
        }
    }
    
    // First find the minimal k
    int min_k = MAX;
    for (int j = S; j < MAX; j++) {
        if (dp[n][j] < min_k) {
            min_k = dp[n][j];
        }
    }
    
    // Then find the j with max f[n][j] among those j >= S and dp[n][j] == min_k
    int max_f = -1;
    int best_j = -1;
    for (int j = S; j < MAX; j++) {
        if (dp[n][j] == min_k && f[n][j] > max_f) {
            max_f = f[n][j];
            best_j = j;
        }
    }
    
    int t = S - max_f;
    cout << min_k << " " << t;
    
    return 0;
}