#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll MOD=1e9+7;
int main()
{
fastio;
    string s;cin>>s;
    int n=s.length();
    s=' '+s;
    // dp[i][j] is no. of integers ending at s[i] s.t they leave rem j upon mod13
    ll dp[n+1][13];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1; // empty string -> 0 rem possible
    for(int i=1;i<=n;i++){
        for(int j=0;j<13;j++){
            if(s[i]=='?'){
                for(int d=0;d<10;d++){
                    dp[i][(10*j+d)%13]+=dp[i-1][j];
                    dp[i][(10*j+d)%13]%=MOD;
                }
            }
            else{
                int d=s[i]-'0';
                dp[i][(10*j+d)%13]+=dp[i-1][j];
                dp[i][(10*j+d)%13]%=MOD;
            }
        }
    }
    cout<<dp[n][5];
    return 0;
}