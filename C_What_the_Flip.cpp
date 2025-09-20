#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll MOD=1e9+7;
const ll MAX=1e6;
ll dp[MAX+1][2][2];
// B87678
int main()
{
fastio;
// precompute
    for(ll i=0;i<=MAX;i++){
        for(ll j=0;j<2;j++){
            for(ll k=0;k<2;k++){
                dp[i][j][k]=0;
            }
        }
    }
    dp[2][0][1]=dp[2][1][0]=dp[2][1][1]=1;
    for(ll i=3;i<=MAX;i++){
        dp[i][0][1]=dp[i-1][1][0];
        dp[i][1][1]=dp[i-1][0][1];
        dp[i][1][0]=(dp[i-1][0][1]+dp[i-1][1][1])%MOD;
    }
    ll tt;cin>>tt;
    while(tt--){
       ll k;cin>>k;
        if(k==1){
            cout<<2<<"\n";
            continue;
        }
        cout<<(dp[k][0][1]+dp[k][1][0]+dp[k][1][1])%MOD<<"\n";
    }
    return 0;
}