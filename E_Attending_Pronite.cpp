#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve() {
    int N;
    cin >> N;
    vector<ll> A(N + 1), diff(N + 2, 0);  // Difference array

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    int Q;
    cin >> Q;
    
    while (Q--) {
        int type, L, R, X;
        cin >> type >> L >> R >> X;
        if (type == 1) {
            diff[L] += X;
            diff[R + 1] -= X;
        } else {
            diff[L] -= X;
            diff[R + 1] += X;
        }
    }

    // Apply the difference array to get final A[]
    for (int i = 1; i <= N; i++) {
        diff[i] += diff[i - 1];
        A[i] += diff[i];
    }

    // Compute the magical sum
    ll sum1 = 0, sum2 = 0, sum3 = 0;
    
    for (int i = 1; i <= N; i++) {
        sum1 = (sum1 + A[i]) % mod;
        sum2 = (sum2 + A[i] * sum1) % mod;
        sum3 = (sum3 + A[i] * sum2) % mod;
    }
    
    cout << sum3 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while (T--) {
        solve();
    }
    
    return 0;
}
