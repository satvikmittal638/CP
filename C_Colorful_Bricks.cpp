#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    const ll MOD=998244353;
    ll n,m,k;cin>>n>>m>>k;
    /*
    dp[i][j] denotes number of ways to color bricks [1,i] s.t. there are j such bricks
    which have colors different from their neighbours
    */
    vector<vector<ll>> dp(n+1,vector<ll>(k+1,0ll));
    dp[1][0]=m;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j]=dp[i-1][j]+(j>0?dp[i-1][j-1]*(m-1):0);
            dp[i][j]%=MOD;
        }
    }
    cout<<dp[n][k];
    return 0;
}