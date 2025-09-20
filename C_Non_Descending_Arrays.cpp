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
       int n;cin>>n;
       vector<int> a(n+1),b(n+1);
       for(int i=1;i<=n;i++) cin>>a[i];
       for(int i=1;i<=n;i++) cin>>b[i];
       vector<vector<ll>> dp(n+1,vector<ll>(2,0ll));

       dp[1][0]=1;
       dp[1][1]=1;
       for(int i=2;i<=n;i++){
        if(a[i-1]<=a[i] && b[i-1]<=b[i]){
            dp[i][0]+=dp[i-1][0];
            dp[i][1]+=dp[i-1][1];
        }
        if(b[i-1]<=a[i] && a[i-1]<=b[i]){
            dp[i][0]+=dp[i-1][1];
            dp[i][1]+=dp[i-1][0];
        }
        dp[i][0]%=MOD;
        dp[i][1]%=MOD;
       }
       cout<<(dp[n][0]+dp[n][1])%MOD<<'\n';
    }
    return 0;
}