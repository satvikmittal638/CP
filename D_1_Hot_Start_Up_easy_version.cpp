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
       int n,k;cin>>n>>k;
       vector<ll> a(n+1),cold(k+1),hot(k+1);
       for(int i=1;i<=n;i++) cin>>a[i];
       for(int i=1;i<=k;i++) cin>>cold[i];
       for(int i=1;i<=k;i++) cin>>hot[i];
       ll dp[n+1][k+1][k+1];
       // dp[i][j][k] is ans for [1,i] if j ran last on cpu-0, k ran last on cpu-1
       for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][a[i]][j]=min(dp[i-1][])
        }
       }
    }
    return 0;
}