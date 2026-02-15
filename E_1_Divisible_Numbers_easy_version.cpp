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
       ll a,b,c,d;cin>>a>>b>>c>>d;
       ll ansx=-1,ansy=-1;
       for(ll y=b+1;y<=d;y++){
        ll lo=((a+1)*y+a*b-1)/(a*b),hi=(c*y)/(a*b);
        ll g=gcd(a*b,y),cury=y/g;
        // error(y,lo,hi,g);
        // cerr<<'\n';
        ll p=(lo+cury-1)/cury;
        if(p<=hi/cury){
            ll k=p*cury;
            ansy=y;
            ansx=(k*a*b)/y;
            break;
        }
       }
       cout<<ansx<<' '<<ansy<<'\n';

    }
    return 0;
}