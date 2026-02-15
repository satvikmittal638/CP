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
       ll x,y;cin>>x>>y;
       for(ll i=0;i<30;i++){
        ll mask=(1ll<<i);
        if((x&mask) && (y&mask)){
            // add 1 at this position to set it to 0
            x+=mask;
        }
       }
       // clear mSB of x
       cout<<x<<' '<<y<<'\n';
    }
    return 0;
}