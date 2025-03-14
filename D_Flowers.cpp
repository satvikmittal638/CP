#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    const ll N=1e5,MOD=1e9+7;
    int t,k;cin>>t>>k;
    vector<ll> dp(N+1,1ll);
    // base case-take all R(take nothing for dp[0] is also a single choice)
    for(int i=k;i<=N;i++){
        /*
        if s[i]='W', the previous k-1 chars must be W and hence we now solve for i-(k-1)-1=i-k
        if s[i]='R', the previous chars can be anything, so we solve again for i-1
        
        */
        dp[i]=dp[i-1]+dp[i-k];
        dp[i]%=MOD;
    }
    for(int i=1;i<=N;i++){
        dp[i]+=dp[i-1];
        dp[i]%=MOD;
    }
    while(t--){
        int a,b;cin>>a>>b;
        cout<<(dp[b]-dp[a-1]+MOD)%MOD<<"\n";
    }
    return 0;
}