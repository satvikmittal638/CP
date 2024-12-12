#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;

void precompute(vector<vector<int>>& prefix, vector<int>& factor_count) {
    // Sieve to count #distinct prime factors
    for (int i = 2; i <= MAXN; ++i) {
        if (factor_count[i] == 0) { // i is prime
            // increment factor count of all multiples of i(including i itself)
            for (int j = i; j <= MAXN; j += i) {
                ++factor_count[j];
            }
        }
    }

    // Build prefix sum arrays for each possible n-factorful count
    // prefix[n][x] gives the count of numbers ≤  x  that are  n-factorful.
    for (int n = 0; n <= 10; ++n) {
        for (int i = 1; i <= MAXN; ++i) {
            prefix[n][i] = prefix[n][i - 1] + (factor_count[i] == n);
        }
    }
}

int main() {
    int T;
    cin >> T;

    vector<int> factor_count(MAXN + 1, 0);
    vector<vector<int>> prefix(11, vector<int>(MAXN + 1, 0));

    precompute(prefix, factor_count);

    while (T--) {
        int a, b, n;
        cin >> a >> b >> n;
        cout << prefix[n][b] - (a > 1 ? prefix[n][a - 1] : 0) << '\n';
    }

    return 0;
}