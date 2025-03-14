#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    const int N=505;
    ll n,m,b,mod;cin>>n>>m>>b>>mod;
    vector<int> a(n+1);for(int i=1;i<=n;i++)cin>>a[i];
    /*
    dp[i][j][k] denotes no. of good plans  using only first i programmers,
    and writing total of j lines of code whilst introducing exactly k bugs
    
    dp[i][j][k]=dp[i-1][j][k]+dp[i][j-1][k-a[i]]

    TODO:Idea used:similar to pascal's triangle--> not understood?
    */
    vector<vector<ll>> dp(N,vector<ll>(N,0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<=b;k++){
                ll cur=dp[j][k];
                if(k>=a[i])cur+=dp[j-1][k-a[i]];
                cur%=mod;
                dp[j][k]=cur; // overwrite the same dp
            }
        }
    }
    ll ans=0ll;
    for(int i=0;i<=b;i++){
        ans+=dp[m][i];
        ans%=mod;
    }
    cout<<ans;
    return 0;
}