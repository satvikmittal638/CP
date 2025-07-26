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
const int MAXM=2*1e5;
    int dp[10][MAXM+1];// dp[i][j] denotes length of digit i after applying j operation
    // Base case: 0 operations => digit stays as is
    for(int d = 0; d <= 9; d++) dp[d][0] = 1;
    for(int m = 1; m <= MAXM; m++){
        for(int d = 0; d <= 8; d++){
            dp[d][m] = dp[d+1][m-1];
        }
        dp[9][m] = (dp[0][m-1] + dp[1][m-1]) % MOD;
    }    
    int tt;cin>>tt;
    while(tt--){
        string n;
       int m;cin>>n>>m;
       ll ans=0ll;
       for(auto d:n){
        ans+=dp[d-'0'][m];
        ans%=MOD;
       }
       cout<<ans<<"\n";

    }
    return 0;
}