#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll MOD=1e9+7;
const ll maxn = 1030;
ll C[maxn + 1][maxn + 1];
int main()
{
fastio;
    //precompute binomial coeff
    C[0][0] = 1;
    for (int n = 1; n <= maxn; ++n) {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k)
            C[n][k] = (C[n - 1][k - 1] + C[n - 1][k])%MOD;
    }
    int n,m;cin>>n>>m;
    cout<<C[n+2*m-1][2*m];
    return 0;
}