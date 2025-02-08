#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    
    // Read the number of stones in each bag
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    set<ll> distinct_xors;
    
    // Iterate through all subsets
    for (int mask = 0; mask < (1 << N); mask++) {
        ll xor_value = 0;
        
        // Iterate through each bit of the subset
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                xor_value ^= A[i];
            }
        }
        
        // Add the XOR of this subset to the set of distinct XOR values
        distinct_xors.insert(xor_value);
    }
    
    // The answer is the size of the set of distinct XOR values
    cout << distinct_xors.size() << endl;
    
    return 0;
}