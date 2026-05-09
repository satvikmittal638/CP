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
       ll n, m, l;
        cin >> n >> m >> l;
        vector<ll> a(n);
        for(auto &i:a) cin>>i;

        ll accDang = 0;
        ll lst = 0;

        for (int i = 0; i < n; i++) {
            accDang += (a[i] - lst);
            
            ll mxDang = (accDang + m - 1) / m;
            
            accDang -= mxDang;
            
            lst = a[i];
        }
        // handle rem
        accDang += (l - lst);
        
        ll ans = (accDang + m - 1) / m;
        cout << ans << '\n';
    }
    return 0;
}