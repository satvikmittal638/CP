#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // You can implement a function here that calculates the variance
        // after `p` operations and multiplies by n^2.
        
        // Example logic for variance calculation could be:
        // Sort the array, perform operations, then compute the variance.
        
        vector<long long> results(m, 0); // To store the results for p = 1 to m
        
        // Process the array for each p (operations count)
        // Update the array optimally and compute variance for each operation count
        
        for (int i = 0; i < m; ++i) {
            // Add logic to apply `i+1` operations and compute variance
            // This might involve using a greedy or dynamic programming approach
            // to minimize variance.
            
            // Placeholder: just assign a default value for now
            results[i] = 0;
        }
        
        for (auto result : results) {
            cout << result << " ";
        }
        cout << endl;
    }

    return 0;
}