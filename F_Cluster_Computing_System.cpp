#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    ll n;cin>>n;
    vector<ll> p(n);for(auto &i:p) cin>>i;
    vector<ll> pref(n),suf(n);
    pref[0]=p[0];
    suf[n-1]=p[n-1];
    for(ll i=1;i<n;i++){
        pref[i]=gcd(pref[i-1],p[i]);
    }
    for(ll i=n-2;i>=0;i--){
        suf[i]=gcd(suf[i+1],p[i]);
    }
    ll ans=0ll;
    for(ll i=1;i<n-1;i++){
        ans+=min(pref[i],suf[i]);
    }
    ans+=pref[n-1];
    cout<<ans<<'\n';
    return 0;
}