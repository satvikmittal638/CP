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
       ll m,x;cin>>m>>x;
       vector<ll> c(m),h(m);
       for(int i=0;i<m;i++)cin>>c[i]>>h[i];
       /*
       dp[j] denotes the minm cost required to achieve happiness j
       */
      ll N=accumulate(all(h),0ll);
       vector<ll> dp(N+1,INF);
       dp[0]=0; // base case
       for(int i=0;i<m;i++){
        for(int j=N;j>=h[i];j--){
            if(dp[j-h[i]]+c[i]<=i*x) dp[j]=min(dp[j],dp[j-h[i]]+c[i]);
        }
       }

       for(int i=N;i>=0;i--){
        if(dp[i]<INF) {
            cout<<i<<"\n";
            break;
        }
       }
    }
    return 0;
}