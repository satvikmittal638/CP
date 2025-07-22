#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;

    // c[i] will be the final answer. We first add leftovers, then full drinks.
    vector<ll> c(n, 0ll); 

    // cnt is the difference array for counting full drinks for each taster.
    vector<ll> cnt(n + 1, 0ll); 

    vector<ll> p(n, 0ll);
    partial_sum(all(b), p.begin());

    for (int i = 0; i < n; i++) {
        // For tea i, we find the cutoff taster. Tasters are i, i+1, ...
        // Sum of capacities of tasters before i (i.e., 0 to i-1)
        ll prvs_sum = (i > 0) ? p[i-1] : 0;
        
        // We need to find the first taster j (>= i) where the total demand
        // from tasters i to j exceeds the available tea a[i].
        // The condition is: (p[j] - prvs_sum) > a[i], or p[j] > a[i] + prvs_sum.
        // We use upper_bound to find the first element strictly greater than the target.
        auto it = upper_bound(p.begin() + i, p.end(), a[i] + prvs_sum);
        int j = it - p.begin(); // j is the 0-based index of the cutoff taster.

        // Tasters from i to j-1 drink their full capacity.
        if (j > i) {
            cnt[i]++;
            cnt[j]--; 
        }

        // Taster j (if they exist, i.e., j < n) gets the leftover amount from tea i.
        if (j < n) {
            ll drunk = (j > i) ? (p[j - 1] - prvs_sum) : 0;
            c[j] += a[i] - drunk;
        }
    }

    partial_sum(cnt.begin(), cnt.end() - 1, cnt.begin());

    // Add the amounts from full drinks to our answer array 'c'.
    for (int i = 0; i < n; i++) {
        c[i] += cnt[i] * b[i];
    }

    for (int i = 0; i < n; i++) {
        cout << c[i]<<" ";
    }
    cout << "\n";
}

int main() {
    fastio;
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}