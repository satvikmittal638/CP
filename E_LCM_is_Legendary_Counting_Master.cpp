#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll MOD=998244353;
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,m;cin>>n>>m;
       vector<int> a(n+1);
       for(int i=1;i<=n;i++)cin>>a[i];
       // dp[i][j] is no. of seqn of length i ending at value j
       vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
        // base case(a[1]=1 is needed for equality)
        if(a[1]==1 || a[1]==0) dp[1][1]=1;
        else{
            cout<<"0\n";
            continue;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=m;j++){
                if(dp[i][j]==0) continue; // prune any transitions from unreachable states since we r doing forward updates
                for(int d=1;d*d<=j;d++){
                    if(j%d==0){
                        int next_val = j + d;
                        if(next_val <= m) {
                            if(a[i+1] == 0 || a[i+1] == next_val) {
                                dp[i+1][next_val] = (dp[i+1][next_val] + dp[i][j]) % MOD;
                            }
                        }

                        int d2 = j / d;
                        if(d != d2) {
                            int next_val2 = j + d2;
                            if(next_val2 <= m) {
                                if(a[i+1] == 0 || a[i+1] == next_val2) {
                                    dp[i+1][next_val2] = (dp[i+1][next_val2] + dp[i][j]) % MOD;
                                }
                            }
                        }
                    }
                }
            }
        }
        ll ans=0ll;
        for(int j=1;j<=m;j++){
            ans=(ans+dp[n][j])%MOD;
        }
        cout<<ans<<'\n';
        
    }
    return 0;
}