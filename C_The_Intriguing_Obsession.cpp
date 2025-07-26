#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll MOD=998244353;
const ll maxn = 5000;
ll C[maxn + 1][maxn + 1];
int main()
{
fastio;
// precompute all nCr
C[0][0] = 1ll;
for (int n = 1; n <= maxn; ++n) {
    C[n][0] = C[n][n] = 1ll;
    for (int k = 1; k < n; ++k)
        C[n][k] = (C[n - 1][k - 1] + C[n - 1][k])%MOD;// pascals formula
}
// Precompute all facts
ll fact[maxn+1];
fact[0]=1;
for(ll n=1;n<=maxn;n++){
    fact[n]=(fact[n-1]*n)%MOD;
}
    ll a,b,c;cin>>a>>b>>c;
    auto sum=[&](ll x,ll y){
        ll sum=0ll;
        for(int k=0;k<=min(x,y);k++){
            sum=(sum+(((C[x][k]*C[y][k])%MOD)*fact[k])%MOD)%MOD;
        }
        return sum;
    };
    ll ans=(((sum(a,b)*sum(b,c))%MOD)*sum(c,a))%MOD;
    cout<<ans;
    return 0;
}