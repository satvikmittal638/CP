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
const ll MOD=998244353;

ll fastmmi(ll a) {
    ll res = 1, exp = MOD - 2;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        exp /= 2;
    }
    return res;
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,q;cin>>n>>q;
       vector<ll> a(n),b(n);
       for(auto &i:a) cin>>i;
       for(auto &i:b) cin>>i;
       vector<ll> origa(a),origb(b);
       sort(all(a));
       sort(all(b));
      
       // find initial ans
       ll ans=1ll;
       for(int i=0;i<n;i++){
        ans*=min(a[i],b[i]);
        ans%=MOD;
       }
       cout<<ans<<' ';
       while(q--){
        ll op,x;cin>>op>>x;x--;
        if(op==1){
           // find last elt =a[x] in the sorted version
           int idx=upper_bound(all(a),origa[x])-1-a.begin();
           ans*=fastmmi(min(a[idx],b[idx]));
           ans%=MOD;
           a[idx]++;
           origa[x]++;
           ans*=min(a[idx],b[idx]);
           ans%=MOD;
        }
        else{
             // find last elt =a[x] in the sorted version
           int idx=upper_bound(all(b),origb[x])-1-b.begin();
           ans*=fastmmi(min(a[idx],b[idx]));
           ans%=MOD;
           b[idx]++;
           origb[x]++;
           ans*=min(a[idx],b[idx]);
           ans%=MOD;
            
        }
        cout<<ans<<' ';
       }
       cout<<'\n';
    }
    return 0;
}