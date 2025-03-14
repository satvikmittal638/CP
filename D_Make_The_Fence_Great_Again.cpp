#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    const ll INF=1e18;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<ll> a(n+1),b(n+1);
       for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
       vector<vector<ll>> dp(n+1,vector<ll>(3,0ll));
    //    dp[0][0]=dp[0][1]=dp[0][2]=0
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++){
                dp[i][j]=j*b[i];
                ll subans=INF;
                for(int x=0;x<3;x++){
                    if(a[i-1]+x!=a[i]+j){
                        subans=min(subans,dp[i-1][x]);
                    }
                }
                dp[i][j]+=subans;
            }
        }
        cout<<min({dp[n][0],dp[n][1],dp[n][2]})<<"\n";
    }
    return 0;
}