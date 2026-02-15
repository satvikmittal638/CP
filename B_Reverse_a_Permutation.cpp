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
       vector<int> p(n);for(auto &i:p) cin>>i;
       int tgt=n,l=0;// bring tgt to posn l
       for(int i=0;i<n;i++){
        if(p[i]==tgt){
            tgt--;
            l++;
        }
        else{
            break;
        }
       }
       // now find tgt
       if(tgt!=0){
        int pos=0;
        while(p[pos]!=tgt) pos++;
        reverse(p.begin()+l,p.begin()+pos+1);
       }
       for(int i=0;i<n;i++) cout<<p[i]<<' ';
       cout<<'\n';
    }
    return 0;
}