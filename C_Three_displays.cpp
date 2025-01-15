#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n;cin>>n;
    vector<int> s(n),c(n);
    for(auto &i:s) cin>>i;
    for(auto &i:c) cin>>i;
    vector<vector<int>> dp(3,vector<int>(n,0));
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        dp[0][i]=c[i];
        int min1=INT_MAX,min2=INT_MAX;
        for(int j=0;j<i;j++){
            if(s[j]<s[i]) {
                min1=min(min1,dp[0][j]);
                min2=min(min2,dp[1][j]);
            }
        }
        dp[1][i]=(min1==INT_MAX?INT_MAX:min1+c[i]);
        dp[2][i]=(min2==INT_MAX?INT_MAX:min2+c[i]);
        ans=min(ans,dp[2][i]);
    }
    if(ans==INT_MAX) ans=-1;
    cout<<ans;
    return 0;
}