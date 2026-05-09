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
       ll n;cin>>n;
       vector<ll> f(n+1,0ll);
       for(int i=1;i<=n;i++) cin>>f[i];
       vector<ll> a(n+1,0ll);
       ll s1=0ll,s2=0ll;
       for(ll i=2;i<n;i++){
        a[i]=(f[i-1]-2*f[i]+f[i+1])/2;
        s1+=(i-1)*a[i];
        s2+=a[i];
       }
       a[n]=(f[1]-s1)/(n-1);
       a[1]=(f[1]+f[n])/(n-1)-(s2+a[n]);
       for(int i=1;i<=n;i++) cout<<a[i]<<' ';
       cout<<'\n';
    }
    return 0;
}