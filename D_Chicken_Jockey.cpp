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
       int n;cin>>n;
       vector<ll> h(n+1);for(int i=1;i<=n;i++) cin>>h[i];
       // dp[i] is ans for 1st i mobs when ith mob is killed at last(this is the optimal way)
       vector<ll> dp(n+1,0ll);
       dp[1]=h[1];
       for(int i=2;i<=n;i++){
        dp[i]=min(dp[i-1]+h[i]-1ll,h[i-1]+dp[i-2]+max(0ll,h[i]-(i-1ll)));// deal 1 fall damage or maxm fall damage
       }
       cout<<dp[n]<<'\n';
    }
    return 0;
}