#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll MOD=1e9+7;
ll n,m;
ll dp[2001][2001];
ll rec(int lvl,int cntDif){

    // pruning
    if(cntDif<0) return 0;
    // base(0-indexed)
    if(lvl==n){
        if(cntDif==0) return 1;
        else return 0;
    }
    // cache
    if(dp[lvl][cntDif]!=-1) return dp[lvl][cntDif];
    
    // compute
    // color this brick same as left
    ll ans=rec(lvl+1,cntDif)%MOD;

    // color this brick diff from left(m-1 colors, all give same ans)
    ans+=(m-1)*(rec(lvl+1,cntDif-1)%MOD);
    ans%=MOD;

    return dp[lvl][cntDif]=ans;
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
        memset(dp,-1,sizeof(dp));
       int k;cin>>n>>m>>k;
       cout<<(m*rec(1,k))%MOD<<'\n';
    }
    return 0;
}