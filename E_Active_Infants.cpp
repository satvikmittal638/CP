#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

int main()
{
    fastio;
    int n; cin >> n;
    vector<pair<int,int>> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    
    sort(rall(a));

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -1e18));

    dp[0][0] = 0;
    
    for(int i = 1; i <= n; i++){
        auto [val, pos] = a[i-1];
        
        for(int j = 0; j <= i; j++){
            ll op1 = -1e18, op2 = -1e18;
            
            // place at Left (requires j > 0)
            // it takes the j-th position from left (which is index j)
            if(j > 0) {
                op1 = dp[i-1][j-1] + (ll)val * abs(pos - j);
            }

            // place at Right (requires j < i)
            // it takes the rightmost available spot.
            // spots filled total: i. Left: j. Right: i-j.
            // position is N - (i - j) + 1.
            if(j < i) {
                op2 = dp[i-1][j] + (ll)val * abs((n - i + j + 1) - pos);
            }

            dp[i][j] = max(op1, op2);
        }
    }
    
    ll ans = 0;
    for(int j = 0; j <= n; j++) ans = max(ans, dp[n][j]);
    cout << ans;
    return 0;
}