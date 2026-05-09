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
       ll a,b,c,m;cin>>a>>b>>c>>m;
       ll p=lcm(a,b),q=lcm(b,c),r=lcm(c,a),z=lcm(p,c);
       ll ansa=0ll,ansb=0ll,ansc=0ll;
       ansa+=6*(m/a-m/p-m/r+m/z)+3*(m/p-m/z + m/r-m/z)+2*(m/z);
       ansb+=6*(m/b-m/q-m/p+m/z)+3*(m/q-m/z + m/p-m/z)+2*(m/z);
       ansc+=6*(m/c-m/q-m/r+m/z)+3*(m/q-m/z + m/r-m/z)+2*(m/z);
       
       cout<<ansa<<' '<<ansb<<' '<<ansc<<'\n';
    }
    return 0;
}