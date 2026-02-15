#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

#ifdef LOCAL
    #define debug_out(x) cerr << "\033[1;32m[JUDGE]: " << x << "\033[0m" << endl;
#else
    #define debug_out(x)
#endif

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
       int cnt;cin>>cnt;
       int x=1;
       int ans=0,left=cnt;
       while(left>0){
        cout<<"- "<<x<<endl;
        int newCnt;cin>>newCnt;
        // this bit was 1
        if(newCnt==cnt-1){
            left--;
            ans|=x;
            x<<=1;
        }
        // this bit was 0
        else{
            int trail0s=newCnt-cnt+1;
            // all trailing 0s became 1 and the 1 just ahead of them became 0
            x<<=trail0s;
            ans|=x; // there was a 1 after the block of 0s
            x<<=1;
            left--;
        }
        cnt=newCnt;
       }
       cout<<"! "<<ans<<endl;
    }
    return 0;
}