#include<bits/stdc++.h>
using namespace std;
int main()
{
    const int MAX=1e5;
    int n;cin>>n;
    vector<long long> cnt(MAX+1,0);
    long long mx=INT_MIN;
    for(int i=0;i<n;i++){
        long long a;cin>>a;
        cnt[a]++;
        mx=max(a,mx);
    }
// dp[i] denotes the maxm score obtained after using all elts of the array from 1..i
    vector<long long> dp(mx+1); 
    dp[0]=0;
    dp[1]=cnt[1];
    for(int i=2;i<=mx;i++){
        // if u use i-1, u can't use i
        // if u use i, u can't use i-1
        dp[i]=max(dp[i-1],i*cnt[i]+dp[i-2]);
    }
    cout<<dp[mx];
    return 0;
}