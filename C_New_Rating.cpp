#include<bits/stdc++.h>
using namespace std;


int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
	    vector dp(n+1, vector(3, INT_MIN));
       dp[0][0]=0;
       for(int i=1;i<=n;i++){
        int a;cin>>a;
        dp[i][0]=dp[i-1][0];
        if(dp[i-1][0]>a) dp[i][0]--;
        else if(dp[i-1][0]<a) dp[i][0]++;
        
        dp[i][1]=max(dp[i-1][0],dp[i-1][1]);

        dp[i][2]=max(dp[i-1][1],dp[i-1][2]);
        if(dp[i][2]<a) dp[i][2]++;
        else if(dp[i][2]>a) dp[i][2]--;
       }
       cout<<max(dp[n][1],dp[n][2])<<"\n";
    }
    return 0;
}