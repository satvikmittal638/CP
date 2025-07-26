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
//precompute binomial coeff
    const ll maxn = 1000;
    ll C[maxn + 1][maxn + 1];
    C[0][0] = 1;
    for (int n = 1; n <= maxn; ++n) {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k)
            C[n][k] = (C[n - 1][k - 1] + C[n - 1][k])%MOD;
    }

    ll k;cin>>k;
    vector<ll> c(k);for(auto &i:c) cin>>i;
    ll ans=1ll,sum=c[0];// f[1]=1
    for(int i=1;i<k;i++){
        sum+=c[i];
        ans*=C[sum-1][c[i]-1];
        ans%=MOD;
    }
    cout<<ans;

    return 0;
}