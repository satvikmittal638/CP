#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       string s,t;cin>>s>>t;
       int n=s.length();
       vector<vector<int>> dp(n+1,vector<int>(26,INT_MAX)); // dp[i][j] is the minm index in [i,n-1] s.t. s[dp[i][j]]=j
       for(int i=n-1;i>=0;i--){
        for(int j=0;j<26;j++) dp[i][j]=dp[i+1][j];// first use the already computed value
        dp[i][s[i]-'a']=i; // minimize it if possible(since i is in decreasing order)
       }


       // 1 opn is always possible(except for -1 case)
       // we start taking chars from beginning of s
       int ans=1,pos=0;
       for(int i=0;i<t.size();i++){
        // reset the pointer(when we reach the end or a char is not found in s from cur position till the end)--> we start with another operation
        if(pos==s.size() || dp[pos][t[i]-'a']==INT_MAX){
            pos=0;// go back to start
            ans++;
        }
        //a char in t can't be found in whole of s-> no ans possible
        if(dp[pos][t[i]-'a']==INT_MAX && pos==0){
            ans=-1;
            break;
        }
        pos=dp[pos][t[i]-'a']+1; // taken the char s[pos], now we can only go ahead of that chars position in the same operation
       }
       cout<<ans<<"\n";
    }
    return 0;
}