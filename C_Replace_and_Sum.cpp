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
       ll n,q;cin>>n>>q;
       vector<ll> a(n+1),b(n+1);
       for(ll i=1;i<=n;i++) cin>>a[i];
       for(ll i=1;i<=n;i++) cin>>b[i];
       for(ll i=1;i<=n;i++) a[i]=max(a[i],b[i]);
       for(ll i=n-1;i>=1;i--) a[i]=max(a[i],a[i+1]);
        vector<ll> s(n+1,0);
       for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i];
       while(q--){
        ll l,r;cin>>l>>r;
        cout<<(s[r]-s[l-1])<<' ';
       }
       cout<<'\n';
    }
    return 0;
}