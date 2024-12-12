#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        // For n = 3, it's impossible to create a valid permutation
        if (n <= 4) {
            cout << -1 << '\n';
            continue;
        }

        
        vector<int> perm;

        // Add even numbers first
        for (int i = 2; i <= n; i += 2) {
            if(i!=4) perm.push_back(i);
        }
        perm.push_back(4);
        perm.push_back(5);
        // Add odd numbers next
        for (int i = 1; i <= n; i += 2) {
            if(i!=5) perm.push_back(i);
        }
        // Output the permutation
        for (int x : perm) {
            cout << x << " ";
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}