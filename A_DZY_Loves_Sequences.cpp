#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    fastio;
    int n; cin >> n;
    if (n <= 2) {
        cout << n;
        return 0;
    }

    vector<int> a(n), l(n, 1), r(n, 1);
    for (auto &x : a) cin >> x;

    // l[i]: length of increasing subarray ending at i
    for (int i = 1; i < n; i++)
        if (a[i - 1] < a[i])
            l[i] = l[i - 1] + 1;

    //r[i]: length of increasing subarray starting at i
    for (int i = n - 2; i >= 0; i--)
        if (a[i] < a[i + 1])
            r[i] = r[i + 1] + 1;

    // Case 1: Length of the longest existing run.
    int ans = *max_element(l.begin(), l.end());
    
    // for Case 3 (extending any single run by one)
    // The result is at least the longest run + 1 (if possible).
    if (ans < n) {
        ans = ans + 1;
    }

    // Case 2: Change one element at position i to merge two segments.
    for (int i = 1; i < n - 1; i++) {
        if (a[i - 1] + 1 < a[i + 1])
            ans = max(ans, l[i - 1] + 1 + r[i + 1]);
    }

    cout << ans;
    return 0;
}