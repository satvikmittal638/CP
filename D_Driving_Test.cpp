#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int INF=1e9;
const int MAX=301;
int main()
{
fastio;
    int n;cin>>n;
    /*
    dp[i][j][k] is length of longest subsequence of non-violating events from [1,i] s.t. after all of these events I have a speed limit of j and k=1 if overtake is allowed
    */
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(MAX+1,vector<int>(2,-INF)));
    dp[0][MAX][1]=0; // base case:when just started
    int t,s;
    for(int i=1;i<=n;i++){
        cin>>t;
        if(t==1 || t==3) cin>>s;
        for(int j=1;j<=MAX;j++){
            for(int k=0;k<=1;k++){
                // carry forward
                dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);

                switch(t){
                    case 1: 
                        if(s <= j) 
                            dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k] + 1);
                        break;

                    case 2: 
                        if(k == 1) 
                            dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k] + 1);
                        break;

                    case 3: 
                        dp[i][s][k] = max(dp[i][s][k], dp[i-1][j][k] + 1);
                        break;

                    case 4: 
                        dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][k] + 1);
                        break;

                    case 5: 
                        dp[i][MAX][k] = max(dp[i][MAX][k], dp[i-1][j][k] + 1);
                        break;

                    case 6: 
                        dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][k] + 1);
                        break;

                    default:
                        // do nothing
                        break;
                }
            }
        }
    }
    int ans=0;
    for(int j=0;j<=MAX;j++){
        for(int k=0;k<=1;k++){
            ans=max(ans,dp[n][j][k]);
        }
    }
    cout<<n-ans;
    return 0;
}