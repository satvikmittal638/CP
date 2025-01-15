#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    string s;cin>>s;
    int n=s.length();
    vector<vector<bool>> isPalin(n,vector<bool>(n,0));
    // odd length-> 1 centre
    for(int c=0;c<n;c++){
        int i=c,j=c;
        while(i>=0 && j<n && s[i]==s[j]){
            isPalin[i][j]=1;
            i--;j++;
        }
    }
    // even length-> 2 centre
    for(int c=0;c<n-1;c++){
        int i=c,j=c+1;
        while(i>=0 && j<n && s[i]==s[j]){
            isPalin[i][j]=1;
            i--;j++;
        }
    }
    /*
dp[i] denotes the ans for [0,i]
sum[i] denotes number of palindromic substrings in [0,i]
    */
    vector<ll> dp(n,0ll),sum(n,0ll);
    for(int i=0;i<n;i++){
        if(i>0)sum[i]=sum[i-1];
        for(int j=0;j<=i;j++){
            sum[i]+=isPalin[j][i];
        }
        if(i>0)dp[i]=dp[i-1];
        for(int j=1;j<=i;j++){
            dp[i]+=isPalin[j][i]*sum[j-1];
        }
    }
    cout<<dp[n-1];
    return 0;
}