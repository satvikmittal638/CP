#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

int main() {
    fastio;
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;

        auto isSafe = [&](int k) {
            vector<int> pref(n, 1);
            for (int i = n - 1; i >= 0 && k; i--) {
                if (s[i] == '1') {
                    pref[i] = -1; // Free item
                    k--;
                }
            }
            int curSum = 0;
            for (int i = 0; i < n; i++) {
                curSum += pref[i];
                if (curSum < 0) return false; // Fail early if negative
            }
            return true;
        };

        // Binary Search on max `k`
        int lo = 0, hi = n / 2, kans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (isSafe(mid)) {
                kans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        // Compute the initial sum of indices
        ll ans = 1LL * n * (n + 1) / 2;
        int i = n - 1;

        // Get discount on the last `kans` items (having `1`)
        while (kans > 0 && i >= 0) {
            if (s[i] == '1') {
                ans -= (i + 1);
                kans--;
            }
            i--;
        }

        cout << ans << "\n";
    }
    return 0;
}