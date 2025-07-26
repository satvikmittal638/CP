#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll MOD=998244353;
ll fastmmi(ll a) {
    ll res = 1ll, exp = MOD - 2;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        exp /= 2;
    }
    return res;
}
ll frac(ll x,ll y){
    return ((x+MOD)*fastmmi(y+MOD))%MOD;
}
int main()
{
fastio;
    ll n,m;cin>>n>>m;
    vector<vector<ll>> itvls(n,vector<ll>(4));
    for(int i=0;i<n;i++){
        for(auto &i:itvls[i]) cin>>i; //l,r,p,q
    }
    // Group the intervals by r[i] values
    // store indices of interval as in itvls array but group them by r values
    vector<vector<int>> itvl_by_r(m+1,vector<int>());


    vector<ll> dp(m+1,0ll);// dp[i] is probab that all cells from 1 to x are covered exactly once and none of other cells are covered
    // Base case-> no cell covered->all intervals inactive
    dp[0]=1ll;
    for(int i=0;i<n;i++){
        ll l=itvls[i][0],r=itvls[i][1],p=itvls[i][2],q=itvls[i][3];
        dp[0]*=frac(q-p,q);
        dp[0]%=MOD;

        // grouping
        itvl_by_r[r].push_back(i);

    }
    for(int x=1;x<=m;x++){
        for(auto i:itvl_by_r[x]){
            ll l=itvls[i][0],p=itvls[i][2],q=itvls[i][3];
            dp[x]+=(dp[l-1]*frac(p,q-p))%MOD;
            dp[x]%=MOD;
        }
    }
    cout<<dp[m];
    return 0;
}