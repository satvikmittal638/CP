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

int main(){
    fastio;

    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;

        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];

        vector<int> sorted_a = a;
        sort(sorted_a.begin()+1, sorted_a.end());

        vector<int> vis(n+1,0);
        bool ok = 1;

        for(int i=1;i<=n;i++){
            if(vis[i]) continue;

            vector<int> idx;
            int cur = i;

            while(cur<=n){
                vis[cur] = 1;
                idx.push_back(cur);
                cur *= 2;
            }

            vector<int> v1, v2;
            for(auto x: idx){
                v1.push_back(a[x]);
                v2.push_back(sorted_a[x]);
            }

            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());

            if(v1 != v2){
                ok = 0;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}