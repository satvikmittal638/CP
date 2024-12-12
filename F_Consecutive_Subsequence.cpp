#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<int> dp(n+1);
    dp[0]=0;dp[1]=1;
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]==1) dp[i]=dp[i-1]+1;// continue the prvs subsequence
        else dp[i]=1; // start a new subseq
    }
    cout<<dp[n];
    return 0;
}