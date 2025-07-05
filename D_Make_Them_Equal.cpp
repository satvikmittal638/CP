#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    vector<int> dp1(2*1e3+5,INT_MAX); // dp1[i] is minm no. of operations to make i from 1
    dp1[1]=0; // base case
    for(int i=1;i<=1e3;i++){
        for(int x=1;x<=1e3;x++){
            dp1[i+(i/x)]=min(dp1[i+(i/x)],dp1[i]+1);
        }
    }
    // cout<<dp1[1];
    int tt;cin>>tt;
    while(tt--){
       int n,k;cin>>n>>k;
       vector<int> b(n),c(n);for(auto &i:b) cin>>i;
       for(auto &i:c) cin>>i;

       // val of dp1 are quite small, so we can limit k
       int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += dp1[b[i]];
        }
        k = min(k, sum); 
       // Solve standard 0-1 knapsack
      vector<int> dp(k+1, 0);
        for (int i = 0; i < n; ++i) {
        int weight = dp1[b[i]];
        int value = c[i];
        for (int j = k; j >= weight; --j) {
            dp[j] = max(dp[j], dp[j - weight] + value);
        }
        }
        cout << dp[k] << "\n";
    }
    return 0;
}