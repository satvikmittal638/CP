#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
    ll MOD=1e9+7;
fastio;
    int tt;cin>>tt;
    while(tt--){
       ll n,k;cin>>n>>k;
       vector<vector<vector<ll>>> dp(1001,vector<vector<ll>>(1001,vector<ll>(2,0)));
       for(int i=0;i<=1000;i++){
        dp[i][1][0]=dp[i][1][1]=1;
       }
       
    }
    return 0;
}