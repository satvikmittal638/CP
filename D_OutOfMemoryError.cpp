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
       ll n,m,h;cin>>n>>m>>h;
       vector<ll> a(n), del(n,0);
       vector<int> lastUsed(n, -1);for(auto &i:a) cin>>i;
       int reset_id = 0;
       for(int op=0;op<m;op++){
        ll b,c;cin>>b>>c;b--;// 0-indexed
        // this wasn't reset, so do now
        if (lastUsed[b] != reset_id) {
            del[b] = 0;
            lastUsed[b] = reset_id;
        }
        // do a reset now
        if (a[b] + del[b] + c > h) {
            reset_id++;
        } else {
            del[b] += c;
        }
       }
       for(int i=0;i<n;i++){
        // reset any remaining
        if (lastUsed[i] != reset_id) del[i] = 0;
        cout << a[i] + del[i] << ' ';
       }
       cout<<'\n';
    }
    return 0;
}