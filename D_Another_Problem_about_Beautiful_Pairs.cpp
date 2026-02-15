#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

#ifndef ONLINE_JUDGE
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
#else
#define error(args...)
#endif

int main()
{
fastio;
    ll tt;cin>>tt;
    while(tt--){
       ll n;cin>>n;
       vector<ll> a(n);for(auto &i:a) cin>>i;
       // brute on smaller elt
       ll ans=0ll;
       for(ll x=1;x*x<=n;x++){
        for(ll j=0;j<n;j++){
            // j>i
            ll i=j-x*a[j];
            if(i>=0 && a[i]==x) ans++;
            
        }
       }
       for (ll x = 1; x*x <= n; x++) {
        for (ll i = 0; i < n; i++) {
            if (a[i]*a[i] <= n) continue;
            ll j = i + x * a[i];
            if (j < n && a[j] == x) {
                ans++;
            }
        }
        }
       cout<<ans<<'\n';
    }
    return 0;
}