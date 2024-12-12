#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,x;cin>>n>>x;
    vector<int> h(n),s(n);
    for(auto &i:h) cin>>i;for(auto &i:s) cin>>i;
    vector<int> dp(x+1,0);// dp[i] denotes no of pages bought upon spending i amount of money
    // dp[0]=0; // no free books :)
    // traverse every book once
    for(int j=0;j<n;j++){
        for(int i=x;i>=h[j];i--){
        dp[i]=max(s[j]+dp[i-h[j]],dp[i]); // either buy the jth book or not
        }
    }
    // for(auto e:dp) cout<<e<<" ";
    cout<<dp[x];
    return 0;
}