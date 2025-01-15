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
    /*
    dp[i][j] tells whether you can get a subsequence of [0,i] such that
    it is jmod8 (0<=j<8)
    */
    vector<vector<bool>> dp(n,vector<bool>(8,0));
    // tracks from where we got the current value of j
    vector<vector<int>> prev(n,vector<int>(8,-1));

    dp[0][(s[0]-'0')%8]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<8;j++){
            if(dp[i-1][j]){
                // cross out s[i]
                dp[i][j]=1;
                prev[i][j]=j;
                // choose append s[i]
                int newMod=j*10+(s[i]-'0');
                dp[i][newMod%8]=1;
                prev[i][newMod%8]=j;
            }
        }
    }
    // rebuilding the ans
    for(int i=0;i<n;i++){
        if(dp[i][0]){
            string ans="";
        }
    }
    return 0;
}