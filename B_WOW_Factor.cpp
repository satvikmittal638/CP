#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;cin>>s;
    int n=s.length();
    vector<long long> dp(n,0ll); // dp[i] denotes the number of vv till first i characters
    for(int i=1;i<n;i++){
        dp[i]=dp[i-1]+(s[i]=='v' && s[i-1]=='v');
    }
    long long ans=0ll;
    for(int i=2;i<n-2;i++){
        if(s[i]=='o') ans+=dp[i-1]*(dp[n-1]-dp[i]);
    }
    cout<<ans;
    return 0;
}