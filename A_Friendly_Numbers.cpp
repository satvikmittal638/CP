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
       ll x;cin>>x;
       auto sumofDig=[&](ll y){
        ll s=0ll;
        while(y){
            s+=y%10;
            y/=10;
        }
        return s;
       };
       ll ans=0ll;
       for(ll d=0;d<=100;d++){
        if(sumofDig(d+x)==d) ans++;
       }
       cout<<ans<<'\n';
    }
    return 0;
}