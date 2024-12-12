#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        // Arrays to store the maximum reachable heights from each tree
        vector<int> maxHeightFromLeft(n), maxHeightFromRight(n);
        
        // Forward traversal (left to right)
        maxHeightFromLeft[0] = a[0];
        for (int i = 1; i < n; ++i) {
            maxHeightFromLeft[i] = max(maxHeightFromLeft[i - 1], a[i]);
        }
        
        // Backward traversal (right to left)
        maxHeightFromRight[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            maxHeightFromRight[i] = max(maxHeightFromRight[i + 1], a[i]);
        }
        
        // Output the result for each tree
        for (int i = 0; i < n; ++i) {
            cout << max(maxHeightFromLeft[i], maxHeightFromRight[i]) << " ";
        }
        cout << "\n";
    }
    
    return 0;
}