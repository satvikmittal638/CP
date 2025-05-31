#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> d(n);
    for (int& x : d) cin >> x;
    vector<pair<int, int>> obstacles(n);
    for (auto& [l, r] : obstacles) cin >> l >> r;

    vector<int> lo(n + 1), hi(n + 1);
    lo[0] = hi[0] = 0;
    bool possible = true;
    for (int i = 1; i <= n; ++i) {
        int current_d = d[i - 1];
        auto [l, r] = obstacles[i - 1];
        int new_lo, new_hi;
        if (current_d == 0 || current_d == 1) {
            new_lo = lo[i - 1] + current_d;
            new_hi = hi[i - 1] + current_d;
        } else {
            new_lo = lo[i - 1];
            new_hi = hi[i - 1] + 1;
        }
        new_lo = max(new_lo, l);
        new_hi = min(new_hi, r);
        if (new_lo > new_hi) {
            possible = false;
        }
        if (possible) {
            lo[i] = new_lo;
            hi[i] = new_hi;
        }
    }

    if (!possible) {
        cout << -1 << '\n';
        return;
    }

    vector<int> res = d;
    int h = hi[n];
    for (int i = n; i >= 1; --i) {
        int idx = i - 1;
        if (res[idx] != -1) {
            h -= res[idx];
            if (h < lo[i - 1] || h > hi[i - 1]) {
                possible = false;
                break;
            }
        } else {
            int prev_lo = lo[i - 1], prev_hi = hi[i - 1];
            int h_candidate1 = h - 1;
            if (h_candidate1 >= prev_lo && h_candidate1 <= prev_hi) {
                res[idx] = 1;
                h = h_candidate1;
            } else {
                if (h >= prev_lo && h <= prev_hi) {
                    res[idx] = 0;
                } else {
                    possible = false;
                    break;
                }
            }
        }
    }

    if (possible && h == 0) {
        for (int x : res) cout << x << ' ';
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}