#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;cin>>s;
    int n=s.length();
    vector<int> dp(n);
    dp[0]=(n>=1?s[1]==s[0]:0);
    for(int i=1;i<n;i++){
        dp[i]=dp[i-1]+(s[i-1]==s[i]);
    }
    int m;cin>>m;
    while(m--){
        int l,r;cin>>l>>r;
        l--;r--; // convert to 0 based indexing
        cout<<dp[r]-dp[l]<<"\n";
    }
    return 0;
}