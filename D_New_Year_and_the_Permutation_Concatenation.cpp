#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll MOD=998244353;
int main()
{
fastio;
    ll n;cin>>n;
    ll ans=1ll;
    for(int i=2;i<=n;i++){
        ans=(ans*(n+1)+n)%MOD;
    }
    cout<<ans;
    return 0;
}