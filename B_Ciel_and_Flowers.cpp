#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    ll r,g,b;cin>>r>>g>>b;
    ll ans=0ll;
    // max 2 mixed bouquet
    for(int i=0;i<=min(2ll,min({r,g,b}));i++){
        ll cur=i;
        cur+=(r-i)/3+(g-i)/3+(b-i)/3;
        ans=max(ans,cur);
    }

    cout<<ans;
    return 0;
}