#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t;  // Read number of test cases
    
    while (t--) {
        int n;
        cin >> n;  // Read number of columns
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];  // Read the inscriptions in each column
        }

        vector<pair<int, int>> moves;  // Store the moves (pairs of indices)
        
        // We will move all 2's to 1's and all 1's to 0's
        vector<int> one_indices, two_indices;
        
        // Collect indices of columns with 1 and 2 inscriptions
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) one_indices.push_back(i);
            if (a[i] == 2) two_indices.push_back(i);
        }
        
        int idx_1 = 0, idx_2 = 0;
        
        // First move 2's to 1's
        while (idx_2 < two_indices.size()) {
            int u = two_indices[idx_2];
            int v = one_indices[idx_1];
            moves.push_back({u + 1, v + 1});  // Convert to 1-based index
            a[u]--;  // Decrease inscription at u
            a[v]++;  // Increase inscription at v
            idx_2++;
            idx_1++;
        }
        
        // Then move 1's to 0's
        idx_1 = 0;
        vector<int> zero_indices;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) zero_indices.push_back(i);
        }
        
        while (idx_1 < one_indices.size()) {
            int u = one_indices[idx_1];
            int v = zero_indices[idx_1];
            moves.push_back({u + 1, v + 1});  // Convert to 1-based index
            a[u]--;
            a[v]++;
            idx_1++;
        }
        
        // Output the result
        cout << moves.size() << endl;
        for (const auto& move : moves) {
            cout << move.first << " " << move.second << endl;
        }
    }
}

int main() {
    solve();  // Solve the problem
    return 0;
}