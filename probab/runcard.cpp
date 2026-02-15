#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    fastio;
    // R=B=n
    for(int n=1;n<=20;n++){
        double dp[n+1][n+1][2];
        
        // Initialize with 0
        memset(dp, 0, sizeof(dp));
    
        // Base Cases:
        // A sequence of just 1 Red card has 1 run.
        dp[1][0][0] = 1.0; 
        // A sequence of just 1 Black card has 1 run.
        dp[0][1][1] = 1.0;
    
        for(ll r = 0; r <= n; r++){
            for(ll b = 0; b <= n; b++){
                if(r == 0 && b == 0) continue; // Skip empty state
                
                double total = r + b - 1; // Size of the prefix
                
                // Calculate dp[r][b][0] (Ends in Red)
                if(r > 0) {
                    // If r=1, b=0, we hit the base case dp[1][0][0] which is already set.
                    // Otherwise, use the recurrence:
                    if (total > 0) {
                        double term1 = (r > 1) ? (r - 1) * dp[r - 1][b][0] : 0;
                        double term2 = (b > 0) ? b * (dp[r - 1][b][1] + 1) : 0;
                        dp[r][b][0] = (term1 + term2) / total;
                    }
                }
    
                // Calculate dp[r][b][1] (Ends in Black)
                if(b > 0) {
                    if (total > 0) {
                        double term1 = (b > 1) ? (b - 1) * dp[r][b - 1][1] : 0;
                        double term2 = (r > 0) ? r * (dp[r][b - 1][0] + 1) : 0;
                        dp[r][b][1] = (term1 + term2) / total;
                    }
                }
            }
        }
    
        // Final Answer: Average of ending in Red and ending in Black
        // Since R=B=n, the probability of the last card being Red is 0.5
        double ans = 0.5 * dp[n][n][0] + 0.5 * dp[n][n][1];
        
        cout << fixed << setprecision(10) << ans << '\n';

    }
    return 0;
}