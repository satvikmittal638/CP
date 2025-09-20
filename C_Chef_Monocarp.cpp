#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int MAX=500;
const int INF=1e9;
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> t(n+1,0);
       for(int i=1;i<=n;i++) cin>>t[i];
       sort(all(t));
       // dp[i][T] is ans for [1,i] with current minute=T
       vector<vector<int>> dp(n+1,vector<int>(2*n+2,INF));
       dp[0][0]=0;

       for(int i=0;i<=n;i++){
        for(int T=0;T<=2*n;T++){
            if(dp[i][T]==INF) continue;
            if(i<n) dp[i+1][T+1]=min(dp[i+1][T+1],dp[i][T]+abs(t[i+1]-(T+1))); // take the dish at t=T+1
            dp[i][T+1]=min(dp[i][T+1],dp[i][T]); // don't take the dish at t=T+1
        }
       }
       cout<<*min_element(all(dp[n]))<<"\n";
    }
    return 0;
}