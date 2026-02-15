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
        int n; cin>>n;
        string s;cin>>s;
        vector<int> p;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') p.push_back(i);
        }
        if(p.empty()){
            cout << (n + 2) / 3 << '\n';
            continue;
        }
        int ans = p.size();
        ans += (p[0] + 1) / 3;// 1st gap
        ans += (n - 1 - p.back() + 1)/3;// last gap
        for(int i = 0; i < p.size() - 1; i++){
            int gap = p[i+1] - p[i] - 1;
            ans += gap / 3;
        }

        cout << ans << '\n';
    }
    return 0;
}