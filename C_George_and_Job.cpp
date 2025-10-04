#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n,m,k;cin>>n>>m>>k;
    vector<ll> p(n);for(auto &i:p) cin>>i;
    vector<ll> pref(n,0ll);
    partial_sum(all(p),pref.begin());
    vector<vector<ll>> dp(n,vector<ll>(k+1,LLONG_MIN));
    for(int i=0;i<n;i++) dp[i][0]=0ll; // no subarray chosen-> 0 sum
    for (int j = 1; j <= k; ++j) {
        vector<ll> pref_max(n, LLONG_MIN); // gives prefix max over dp[i][j-1] for use when updating dp[i][j]
        for (int i = 0; i < n; ++i) {
            if (i >= m) {
                pref_max[i] = max(pref_max[i - 1], dp[i - m][j - 1]);
                dp[i][j] = pref_max[i] + (pref[i] - pref[i - m]);
            } else if (i == m - 1) {
                if (j == 1) {
                    dp[i][j] = pref[i];
                }
            } else {
                if (i > 0) pref_max[i] = pref_max[i - 1];
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) ans = max(ans, dp[i][k]);
    cout << ans << '\n';
    return 0;
}