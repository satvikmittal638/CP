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
       if(n%2==0){
        for(int i=0;i<n/2;i++){
            cout<<n/2+ i<<' ';
        }
        for(int i=1;i<=n/2;i++){
            cout<<n+i<<' ';
        }
       }
       else{
        vector<long long> ans;
        int mid = n / 2;

        for (int i = -mid; i <= mid; i++) {
            ans.push_back(n + i);
        }

        for (auto &x : ans) x += 2;

        ans[0]--;
        ans[n-1]++;

        ans[n-2]++;
        for (auto x : ans) cout << x << ' ';
       }
       cout<<'\n';
    }
    return 0;
}