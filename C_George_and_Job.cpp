#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n,m,k;cin>>n>>m>>k;
    vector<ll> p(n);for(auto &i:p) cin>>i;
    vector<ll> pref(n,0ll);
    partial_sum(all(p),pref.begin());
    multiset<ll> ms;
    for(int i=m-1;i<n;i++){
        ll cur=pref[i]-(i>=m?pref[i-m]:0ll);
        ms.insert(cur);
    }
    ll ans=0ll;
    // choose top-k sums
    for(int i=0;i<k;i++){
        ans+=*(ms.rbegin());
        ms.erase(prev(ms.end()));
    }
    cout<<ans;
    return 0;
}