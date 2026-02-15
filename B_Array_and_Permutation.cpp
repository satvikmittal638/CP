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
       int n;cin>>n;
       vector<int> p(n),a(n);
       for(auto &i:p) cin>>i;
       for(auto &i:a) cin>>i;
       vector<int> shrinkeda;
       // shrink rpted blocks of a
       for(int i=0;i<n;i++){
        if(shrinkeda.empty() || shrinkeda.back()!=a[i]) shrinkeda.push_back(a[i]);
       }
       // check if shrinkeda is a subsequence of p or not
       int i=0;
        bool ok=1;
       for(auto e:shrinkeda){
        // find 1st occ of e in p
        while(i<n && p[i]!=e) i++;
        if(i==n){
            ok=0;
            break;
        }
        i++;
       }
       cout<<(ok?"YES":"NO")<<'\n';
    }
    return 0;
}