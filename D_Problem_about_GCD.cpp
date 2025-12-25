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
       ll l,r,g;cin>>l>>r>>g;
       ll lo=(l+g-1)/g,hi=r/g;
       if(hi<lo){
        cout<<"-1 -1\n";
        continue;
       }
       ll p=lo,q=hi;
       ll maxd=hi-lo+1,d=maxd;
       bool found=0;
       while(d && !found){
        // try pairs with distance=d
        for(ll l=lo;l+d-1<=hi;l++){
            if(gcd(l,l+d-1)==1){
                p=l;
                q=l+d-1;
                found=1;
                break;
            }
        }
        d--;
       }
       if(found) cout<<p*g<<' '<<q*g<<'\n';
       else cout<<"-1 -1\n";
    }
    return 0;
}