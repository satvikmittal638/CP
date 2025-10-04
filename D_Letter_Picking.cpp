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
       string s;cin>>s;
       int n=s.length();
       // dp[l][r] is outcome for s[l,r) with A moving first
       /*
       -1:A  wins
       0: Draw
       1: B wins
       */
      // A chose c, B chose d, subOut=dp[l'][r'], computes the outcome for [l,r)
      auto getOutcome=[&](char c,char d,int subOut){
        int ans=0;
        if(c==d) ans=subOut;
        else if(c<d) ans=-1;
        else ans=1;
        return ans;
      };
       vector<vector<int>> dp(n+1,vector<int>(n+1,0));// Base:dp[i][i]=0(Draw since s is empty)
       // Traverse in increasing order of length of substring
       for(int len=2;len<=n;len+=2){
        for(int l=0;l<=n-len;l++){
            int r=l+len;
            // Taking max favors B, Taking min favors A
            dp[l][r]=min(max(getOutcome(s[l],s[l+1],dp[l+2][r]),getOutcome(s[l],s[r-1],dp[l+1][r-1])),
                        max(getOutcome(s[r-1],s[l],dp[l+1][r-1]),getOutcome(s[r-1],s[r-2],dp[l][r-2])));
        }
       }
       if(dp[0][n]==-1) cout<<"Alice";
       else if(dp[0][n]==0) cout<<"Draw";
       else cout<<"Bob";
       cout<<'\n';
    }
    return 0;
}