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
       vector<int> ans;
       int sz=1<<n;
       vector<bool> used(sz,0);
       for(int i=n;i>=0;i--){
        int mask=(1<<i)-1;
        // put remaining in ascending
        if(mask == 0) {
            for(int x = 0; x < sz; x++) {
                if(!used[x]) {
                    ans.push_back(x);
                    used[x] = 1;
                }
            }
            break;
        }

        // try to sustain pop count for as long as possible using minimal possible nos
        for (int x = 0; x < sz; x++) {
            if (!used[x] && (x & mask) == mask) {
                ans.push_back(x);
                used[x] = 1;
            }
        }
       }
       for(auto e:ans) cout<<e<<' ';
       cout<<'\n';


    }
    return 0;
}