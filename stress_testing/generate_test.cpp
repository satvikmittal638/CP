#include <bits/stdc++.h>
using namespace std;

int main() {
    // Seed random number generator for different outputs on each run
    srand(time(0));

    // Set constraints here
    int max_n = 100;        // Maximum value for n
    int max_k = 100000;     // Maximum value for k
    int max_val = 100000;   // Maximum value for elements in the vector

    // Randomly select values for n and k within constraints
    int n = rand() % max_n + 1;       // Ensure n >= 1
    int k = rand() % max_k + 1;       // Ensure k >= 1

    // Output n and k
    cout << n << " " << k << endl;

    // Generate a vector of size n with elements in the range [1, max_val]
    for (int i = 0; i < n; i++) {
        cout << rand() % max_val + 1 << " ";  // Ensure element >= 1
    }
    cout << endl;

    return 0;
}