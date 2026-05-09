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
       vector<pair<int,int>> a;
       for(int i=0;i<n;i++){
        int x;cin>>x;
        a.emplace_back(x,i);
       }
       sort(rall(a));
       int r=n-1;
       int op=0;
       for(int i=0;i<n;i++){
        auto [x,ind]=a[i];
        // its a deletable elt
        if(ind<=r){
            r=ind;
            op++;
        }
       }
       cout<<op<<'\n';

    }
    return 0;
}