#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

// Function to get divisors of a number
vector<int> getDivisors(int n) {
    vector<int> divisors;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}

int main() {
    int t; // number of test cases
    cin >> t;
    
    while (t--) {
        int n; // number of elements in the array
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Step 1: Get divisors of the first element
        vector<int> divisors = getDivisors(a[0]);
        set<int> common_divisors(divisors.begin(), divisors.end());
        
        // Step 2: For each number in the array, find the common divisors
        for (int i = 1; i < n; i++) {
            vector<int> current_divisors = getDivisors(a[i]);
            set<int> current_divisors_set(current_divisors.begin(), current_divisors.end());
            
            // Intersect the sets to get the common divisors
            set<int> temp;
            for (int d : common_divisors) {
                if (current_divisors_set.count(d)) {
                    temp.insert(d);
                }
            }
            common_divisors = temp;
        }
        
        // Step 3: If there are no common divisors, output -1
        if (common_divisors.empty()) {
            cout << -1 << endl;
        } else {
            // Step 4: Otherwise, print the smallest common divisor
            cout << *common_divisors.begin() << endl;
        }
    }
    
    return 0;
}