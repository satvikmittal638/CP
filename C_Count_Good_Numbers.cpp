#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll cnt_bad(ll x) {
    // try all subsets
    vector<int> primes = {2, 3, 5, 7};
    int n = primes.size();
    ll res = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
        ll l = 1;
        int bits = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                l *= primes[i];
                ++bits;
            }
        }
        if (bits % 2 == 1) res += x / l;
        else res -= x / l;
    }
    return res;
}

ll cnt_good(ll l, ll r) {
    return (r - cnt_bad(r)) - (l - 1 - cnt_bad(l - 1));
}

int main() {
    int tt;cin>>tt;
    while(tt--){
        ll l, r;
        cin >> l >> r;
        cout << cnt_good(l, r) << '\n';
    }
    return 0;
}