#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    const ll MOD=1e9+7;
    ll x,y;cin>>x>>y;
    ll n;cin>>n;n--;
    n%=6;
    vector<ll> ans={x,y,y-x,-x,-y,x-y};
    cout<<(ans[n]%MOD+MOD)%MOD;
    return 0;
}