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
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<ll> a(n);for(auto &i:a) cin>>i;
       ll ans=0ll;
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            swap(a[i],a[j]);
            ll cur=0ll,mx=0ll;
            for(int i=0;i<n;i++){
                mx=max(mx,a[i]);
                cur+=mx;
            }
            ans=max(cur,ans);
        }
       }
       cout<<ans<<'\n';
    }
    return 0;
}