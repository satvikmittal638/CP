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

       int ans=0;
       for(int d=0;d<=n;d++){
        rotate(s.begin(),s.begin()+1,s.end());
           vector<char> block;
           block.push_back(s[0]);
           for(int i=1;i<n;i++){
            if(block.back()!=s[i]) block.push_back(s[i]);
           }
           ans=max(ans,(int)block.size());
       }
       
       cout<<ans<<'\n';
    }
    return 0;
}