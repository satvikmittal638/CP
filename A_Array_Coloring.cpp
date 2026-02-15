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
       vector<int> a(n);for(auto &i:a) cin>>i;
       vector<pair<int,int>> c1,c2;
       bool col=0;
       for(int i=0;i<n;i++){
        c1.emplace_back(a[i],col);
        col=!col;
       }
       col=1;
       for(int i=0;i<n;i++){
        c2.emplace_back(a[i],col);
        col=!col;
       }
       sort(all(c1));
       sort(all(c2));
       bool found1=1,found2=1;
       for(int i=0;i<n-1;i++){
        if(c1[i].second==c1[i+1].second){
            found1=0;
            break;
        }
       }
       for(int i=0;i<n-1;i++){
        if(c2[i].second==c2[i+1].second){
            found2=0;
            break;
        }
       }
       cout<<((found1|found2)?"YES":"NO")<<'\n';
    }
    return 0;
}