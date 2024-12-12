#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int> h(n),a(n);
    for(auto &i:h) cin>>i;
    for(auto &i:a) cin>>i;

    /*
    Let dp[i] denote the maximum possible beauty of the MI sequence of flowers
    ending at position i

    dp[i]=max(dp[j]) + a[i]
    where 0<=j<i and h[j]<h[i]
    */
   // Brute:O(n^2)
    vector<long long> dp(n),pref(n);

    /*
    Let pref[i] denote the max(dp[j]) 
    where 0<=j<i and h[j]<h[i] 
    TODO--> Can i use binary search somehow?
    */
    dp[0]=a[0];
    for(int i=1;i<n;i++){
        // long long maxSum=0;
        // for(int j=0;j<i;j++){
        //     if(h[j]<h[i]){
        //         maxSum=max(maxSum,dp[j]);
        //     }
        // }
        // dp[i]=maxSum+a[i];

    }
    cout<<dp[n-1];
    return 0;
}