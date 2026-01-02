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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<ll> H(1e6+1,-1);

ll get_hash(ll x) {
    if (H[x]!=-1) return H[x];
    return H[x]=rng();
}
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,q;cin>>n>>q;
       vector<ll> a(n),p(n);for(auto &i:a) cin>>i;
       // hash to random vals
       p[0]=get_hash(a[0]);
       for(int i=1;i<n;i++){
        p[i]=p[i-1]^get_hash(a[i]);
       }
       while(q--){
        int l,r;cin>>l>>r;l--;r--;
        ll xorsum=p[r];
        if(l>0) xorsum^=p[l-1];
        cout<<(xorsum==0?"YES":"NO")<<'\n';
       }
    }
    return 0;
}