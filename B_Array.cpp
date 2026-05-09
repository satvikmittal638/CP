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
       for(int i=0;i<n;i++){
        int cntBigger=0,cntLess=0;
        for(int j=i+1;j<n;j++){
            if(a[j]>a[i]) cntBigger++;
            else if(a[j]<a[i]) cntLess++;
        }
        cout<<max(cntLess,cntBigger)<<' ';
       }
       cout<<'\n';
    }
    return 0;
}