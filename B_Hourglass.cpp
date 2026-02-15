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
       ll s,k,m;cin>>s>>k>>m;
       ll cntFlips=m/k,rem=m%k;
       ll st;
       if(s<k){
        st=s;
       }
       else{
        // cycles of 2
        if(cntFlips%2==0) st=s;
        else st=k;
       }
       ll ans=max(0ll,st-rem); // consume leftover
       cout<<ans<<'\n';
    }
    return 0;
}