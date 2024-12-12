#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto &i : a) cin >> i;
        
        // Find the first node with a different color
        int firstDifferent = -1;
        for (int i = 1; i < n; ++i) {
            if (a[i] != a[0]) {
                firstDifferent = i;
                break;
            }
        }

        // If all elements are the same, output NO
        if (firstDifferent == -1) {
            cout << "NO\n";
            continue;
        }

        // Create connections
        cout << "YES\n";
        for (int i = 1; i < n; ++i) {
            if (a[i] == a[0]) {
                // Connect nodes of the same color to the first different node
                cout << firstDifferent + 1 << " " << i + 1 << "\n";
            } else {
                // Connect nodes of different colors to the first node
                cout << 1 << " " << i + 1 << "\n";
            }
        }
    }
    return 0;
}