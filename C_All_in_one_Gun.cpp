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
       ll n,h,k;cin>>n>>h>>k;
       vector<ll> a(n);for(auto &i:a) cin>>i;
       // smax computation
       vector<ll> smax(n+1,0);
       ll S=0ll;
       for(int i=n-1;i>=0;i--){
        smax[i]=max(smax[i+1],a[i]);
        S+=a[i];
       }
       // fire all floor(h/S) cycles and then reload cycles-1 times
       ll cycles = (h - 1) / S;
       ll ans = cycles * (n + k);
       h -= cycles * S; 
       
       ll pref = 0ll;
       ll pmin = INT_MAX; 
       
       for(int i = 0; i < n; i++){
           pref += a[i];
           pmin = min(pmin, a[i]);
           // swap with smallest on the prefix
           ll max_sum = pref + max(0LL, smax[i + 1] - pmin);
           
           if(max_sum >= h){
               ans += i + 1;
               break;
           }
       }
    cout<<ans<<'\n';
    }
    return 0;
}