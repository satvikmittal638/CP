#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

int main() {
    fastio;
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        ll ans = 0ll;
        vector<ll> myL(n), myR(n);
        set<pair<int, int>> l, r;
        
        for (int i = 0; i < n; i++) {
            ll curL;
            cin >> curL;
            myL[i] = curL;
            ans += curL;
            l.insert({curL,i});
        }
        
        for (int i = 0; i < n; i++) {
            ll curR;
            cin >> curR;
            myR[i] = curR;
            ans += curR;
            r.insert({curR,i});
        }

        int cnt_drop_pair = n - k;
        while (cnt_drop_pair && !l.empty() && !r.empty()) {
            auto minL = l.begin(), minR = r.begin();
            if (minL->first < minR->first) {
                ans -= minL->first;
                int idx = minL->second;
                l.erase(minL);
                r.erase({myR[idx], idx});
            } else {
                ans -= minR->first;
                int idx = minR->second;
                r.erase(minR);
                l.erase({myL[idx], idx});
            }
            cnt_drop_pair--;
        }
        auto minL = l.begin(), minR = r.begin();
        ans-=min(minL->first,minR->first)-1;

        cout << ans << "\n";
    }
    return 0;
}