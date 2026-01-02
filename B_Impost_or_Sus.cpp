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
       string r;cin>>r;
       int n=r.length();
       int ans=0;
       if(r[0]=='u') ans++;
       if(r[n-1]=='u') ans++;
       for(int i=1;i<n-1;i++){
        int len=0;
        if(r[i]=='u'){
            while(i<n-1 && r[i]=='u'){
                len++;
                i++;
            }
        }
        ans+=len/2;
       }
       cout<<ans<<'\n';
    }
    return 0;
}