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
       string s;cin>>s;
       int mn1,mx1;
       // make maxm 1s
       for(int i=1;i<n-1;i++){
        if(s[i-1]=='1' && s[i+1]=='1') s[i]='1';
       }
       mx1=count(all(s),'1');
       // make maxm 0s
       for(int i=1;i<n-1;i++){
        if(s[i-1]=='1' && s[i+1]=='1') s[i]='0';
       }
       mn1=count(all(s),'1');
       cout<<mn1<<' '<<mx1<<'\n';
    }
    return 0;
}