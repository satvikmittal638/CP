#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int MAX=1e3+1;
const ll MOD=1e9+7;
vector<vector<int>> a;
ll dp[MAX][MAX];
// no. of paths path from (0,0) ending at (r,c)
ll rec(int r,int c){
    // prune
    if(r<0 || c<0 || a[r][c]==1) return 0;
    // base case
    if(r==0 && c==0) return a[0][0]==0;
    // cache check
    if(dp[r][c]!=-1) return dp[r][c];
    // compute and save
    ll ans=0ll;
    ans += rec(r-1, c);
    ans += rec(r, c-1);

    return dp[r][c]=ans%MOD;
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,m;cin>>n>>m;
       a.assign(n,vector<int>(m,0));
       for(auto &i:a) for(auto &j:i) cin>>j;
       memset(dp,-1,sizeof(dp));
       cout<<rec(n-1,m-1)<<'\n';
    }
    return 0;
}