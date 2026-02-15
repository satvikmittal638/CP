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
       int cnt0=count(all(s),'0');
       if(is_sorted(all(s))){
        cout<<"Bob\n";
       }
       else{
        cout<<"Alice\n";
        vector<int> ans;
        // choose all 1s in cnt0 prefix
        for(int i=0;i<cnt0;i++){
            if(s[i]=='1') ans.push_back(i+1);
        }
        // choose all 0s in cnt1 suffix
        for(int i=cnt0;i<n;i++){
            if(s[i]=='0') ans.push_back(i+1);
        }
        cout<<ans.size()<<'\n';
        for(auto e:ans) cout<<e<<' ';
        cout<<'\n';
       }
    }
    return 0;
}