#include <bits/stdc++.h>
using namespace std;

mt19937 rng;

int get_rand(int l, int r) {
    uniform_int_distribution<int> dist(l, r);
    return dist(rng);
}

int main(int argc, char* argv[]) {
    int seed = 1;
    if (argc > 1) seed = atoi(argv[1]);
    rng.seed(seed);

    // STRATEGY: 
    // For debugging, we usually output T=1 so we can isolate the failure.
    int t = 1; 
    cout << t << "\n";

    while(t--) {
        // ---------------------------------------------------------
        // CONSTRAINT CONTROL
        // ---------------------------------------------------------
        // Problem says N <= 100. 
        
        // Option 1: Full Random (Good for general logic)
        int n = get_rand(4, 100); 

        // Option 2: Force MAX Constraints (Uncomment to test TLE)
        // int n = 100; 

        // Option 3: Force Edge Cases (Smallest N)
        // int n = 4;
        // ---------------------------------------------------------

        cout << n << "\n";

        // Generate String S
        for(int i = 0; i < n; i++) cout << get_rand(0, 1);
        cout << "\n";

        // Generate String T
        for(int i = 0; i < n; i++) cout << get_rand(0, 1);
        cout << "\n";
    }
    return 0;
}