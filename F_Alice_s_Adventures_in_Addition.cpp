#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // Case 1: If there's a zero in the array and m is 0
        bool found_zero = false;
        for (int num : a) {
            if (num == 0) {
                found_zero = true;
                break;
            }
        }

        if (found_zero && m == 0) {
            cout << "YES\n";
            continue;
        }

        // Case 2: If m is directly one of the numbers
        for (int num : a) {
            if (num == m) {
                cout << "YES\n";
                break;
            }
        }

        // Case 3: Try a direct greedy approach to check combinations
        unordered_set<int> possible_sums;
        possible_sums.insert(0);  // We can always have a sum of 0

        bool possible = false;
        for (int num : a) {
            unordered_set<int> new_sums = possible_sums;

            // Update sums by adding or multiplying
            for (int sum : possible_sums) {
                new_sums.insert(sum + num);  // Addition
                new_sums.insert(sum * num);  // Multiplication
            }

            possible_sums = new_sums;

            if (possible_sums.count(m)) {
                possible = true;
                break;
            }
        }

        if (possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}