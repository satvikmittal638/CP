#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

int main() {
    fastio;
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = a[i] - b[i];
    }
    sort(all(c));

    ll ans = 0ll;
    for (int i = 0; i < n; i++) {
        if(c[i]>0){
            int pos=lower_bound(all(c), -c[i]+1)-c.begin();
            ans+=i-pos;
        }
        
    }
    cout << ans << "\n";
    return 0;
}