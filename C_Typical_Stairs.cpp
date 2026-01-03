#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll INF=1e18;
const ll MOD=1e9+7;
int main()
{
fastio;
    int n,m;cin>>n>>m;
    ll dp[n+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        dp[x]=INF; // invalid state
    }
    dp[0]=1;
    for(int i=1;i<=n;i++){
        if(dp[i]>=INF) continue;
        if(dp[i-1]<INF) dp[i]+=dp[i-1];
        if(i>=2 && dp[i-2]<INF) dp[i]+=dp[i-2];
        dp[i]%=MOD;
    }
    cout<<dp[n];
    return 0;
}