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

// xor of [1,n]
ll xorSum(ll n){
    if(n<0) return 0;
    ll ans;
    switch(n%4){
        case 0:return n;
        case 1:return 1;
        case 2:return n+1;
        case 3:return 0;
    }

}
ll xorRange(ll l,ll r){
    return xorSum(r)^xorSum(l-1);
}
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       ll l,r,i,k;cin>>l>>r>>i>>k;
       // last i bits must be equal to k for mod2^i=k
       ll tot=xorRange(l,r); // xor of all nums
       ll modk=0; // xor of nums=k mod2^i
       ll p=1ll<<i;
       ll newl=(l-k)/p,newr=(r-k)/p;
       if(newl*p+k<l) newl++;
       if (newr * p + k > r) newr--;
       if(newl<=newr){
           modk=(xorRange(newl,newr)<<i);
           // k occurs odd times-> survives xor
           if(((newr-newl+1)&1)) modk^=k;
           tot^=modk;
       }
        error(newl,newr,tot,modk);
        cerr<<endl;
        // check if I can fix k or not
       cout<<tot<<'\n';
    }
    return 0;
}