#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;cin>>n>>k;
    vector<int> h(n+1),dp(n+1,INT_MAX);
    for(int i=1;i<=n;i++) cin>>h[i];
    dp[1]=0;
    dp[2]=abs(h[2]-h[1]);
    for(int i=3;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(i-j>=1)
                dp[i]=min(dp[i],dp[i-j]+abs(h[i]-h[i-j]));
        }
    }
    cout<<dp[n];
    return 0;
}