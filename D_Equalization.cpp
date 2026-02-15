#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0);cin.tie(0);
const ll INF=4e18;
ll dp[61][61][61];
// rec(i,j,k) is minm total cost s.t. we need j right shifts for x, k right shifts for y
// and we are left with 2^i...2^60
ll rec(int i,int j,int k){
    if(i>60){
        // sum attained
        if(j==0 && k==0)return 0;
        // sum not attained
        return INF;
    }
    // prune(invalid state)
    if(j<0||k<0)return INF;

    ll &res=dp[i][j][k];
    if(res!=-1)return res;
    // explore all 3 options
    res=rec(i+1,j,k);
    ll t=rec(i+1,j-i,k);
    if(t<INF)res=min(res,t+(1LL<<i));
    t=rec(i+1,j,k-i);
    if(t<INF)res=min(res,t+(1LL<<i));
    return res;
}
int main(){
    fastio;
    memset(dp,-1,sizeof(dp));
    int tt;cin>>tt;
    while(tt--){
        ll x,y;cin>>x>>y;
        ll ans=INF;
        // brute all possible right shifts of x and y which can make them equal
        for(ll lx=0;lx<=60;lx++){
            for(ll ly=0;ly<=60;ly++){
                if((x>>lx)==(y>>ly)) ans=min(ans,rec(1,lx,ly));
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}