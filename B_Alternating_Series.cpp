#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n; cin >> n;
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 1) cout << -1;
            else cout << (i == n ? 2 : 3);
            cout<<' ';
        }
        cout << '\n';
    }
    return 0;
}