#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,m;cin>>n>>m;
       vector<int> a(n+1),b(n+1);
       for(int i=1;i<=n;i++)cin>>a[i];
       for(int i=1;i<=n;i++)cin>>b[i];
       ll dp[n+2][2];
       /*
       dp[i][0] denotes the minm cost to reach position i after paying a[i] to ith person
       dp[i][1] denotes the minm cost to reach position i after paying b[i] to ith person
       */
       dp[n+1][0]=dp[n+1][1]=0ll;
       for(int i=n;i>=1;i--){
        dp[i][0]=a[i]+min(dp[i+1][0],dp[i+1][1]);
        dp[i][1]=b[i]+min(dp[i+1][0],dp[i+1][1]);
       }
       ll minCost=LLONG_MAX;
       // to stand among first m persons, u must pay some a[i] cost
        for(int i=1;i<=m;i++){
            minCost=min(minCost,dp[i][0]);
        }
        cout<<minCost<<"\n";
    }
    return 0;
}