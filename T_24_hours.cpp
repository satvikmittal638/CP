#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> respect, burden;

bool canAchieve(double r) {
    vector<vector<double>> dp(n, vector<double>(m, -1e18));
    dp[0][0] = respect[0][0] - r * burden[0][0];
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i > 0)
                dp[i][j] = max(dp[i][j], dp[i-1][j] + respect[i][j] - r * burden[i][j]);
            if (j > 0)
                dp[i][j] = max(dp[i][j], dp[i][j-1] + respect[i][j] - r * burden[i][j]);
        }
    }
    
    return dp[n-1][m-1] >= 0;
}

int main() {
    cin >> n >> m;
    respect.resize(n, vector<int>(m));
    burden.resize(n, vector<int>(m));
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> respect[i][j];
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> burden[i][j];
    
    double low = 0, high = 1e6, ans = 0;
    while (high - low > 1e-6) {
        double mid = (low + high) / 2;
        if (canAchieve(mid)) {
            ans = mid;
            low = mid;
        } else {
            high = mid;
        }
    }
    
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}