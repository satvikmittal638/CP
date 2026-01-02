#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll MAX=1e3+1;
const ll MOD=998244353;
ll n;
vector<ll> a;

ll c[MAX][MAX];
ll C(ll n,ll r){
    // prune
    if(n<0 || r<0 || r>n){
        return 0;
    }
    // base
    if(r==0 || r==n) return 1;
    // cache check
    if(c[n][r]!=-1) return c[n][r];
    // compute and save
    ll ans=C(n-1,r)+C(n-1,r-1);
    ans%=MOD;
    return c[n][r]=ans;
}

ll dp[MAX];
// rec(i) is no. of good subsequence on [i,n-1] starting at a[i]
ll rec(ll i){
    // prune
    // empty
    if(i>=n){
        return 1;
    }
    // base

    // cache check
    if(dp[i]!=-1) return dp[i];
    // compute and save
    ll ans=0ll;
    // for a valid length
    if(0<a[i] && a[i]<n){
        // start at this
        // a[i] is chosen, so now choose more a[i] no. of elts
        // to make a total of a[i]+1 elts for a good array
        for(ll j=a[i];i+j<n;j++){
            ans+=rec(i+j+1)*C(j,a[i]);
            ans%=MOD;
        }
    }
    return dp[i]=ans;

}


int main()
{
fastio;
    cin>>n;
    a.assign(n,0);for(auto &i:a) cin>>i;
    memset(c,-1,sizeof(c));
    memset(dp,-1,sizeof(dp));
    ll ans=0ll;
    for(ll i=0;i<n;i++){
        ans+=rec(i);
        ans%=MOD;
    }
    cout<<ans;
    return 0;
}