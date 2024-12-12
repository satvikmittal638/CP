#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n);for(auto &i:a) cin>>i;
       // dp[i] denotes minm opn to make [i,n-1] beautiful
       vector<long long> dp(n+1);
       dp[n]=0;// TODO-why this?-> empty subarray is trivially beautiful?
       dp[n-1]=1;// the only way to make a single elt beautiful is to remove it
       for(int i=n-2;i>=0;i--){
        // either remove a[i] -> then need to make [i+1,n-1] beautiful
        // or keep a[i]->[i,i+a[i]] is made a block and now make [i+a[i]+1,n-1] beautiful
        dp[i]=min(dp[i+1]+1,(i+a[i]<n)?dp[i+a[i]+1]:INT_MAX);
       }
       cout<<dp[0]<<"\n";
    }
    return 0;
}