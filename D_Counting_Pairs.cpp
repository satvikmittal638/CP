#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

int main()
{
    fastio;
    int tt; cin >> tt;
    while (tt--) {
        ll n, x, y; cin >> n >> x >> y;
        vector<ll> a(n); for (auto &i : a) cin >> i;
        sort(all(a));

        ll sum = accumulate(all(a), 0ll), ans = 0ll;
        for (int i = 0; i < n; i++) {
            ll hi = sum - x - a[i], lo = sum - y - a[i];

            // Get the first element >= lo
            auto it_l = lower_bound(all(a), lo);
            // Get the first element > hi
            auto it_r = upper_bound(all(a), hi);

            // The count of elements in the range [lo, hi]
            ll count = it_r - it_l;

            // Subtract 1 if the element a[i] is in the range [lo, hi]
            if (it_l <= a.begin() + i && a.begin() + i < it_r) {
                count--;
            }

            ans += count; // Add the valid count to the result
        }
        cout << ans/2 << "\n";
    }
    return 0;
}