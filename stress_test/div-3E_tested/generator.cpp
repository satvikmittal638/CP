#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    // Initialize random seed based on clock
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    // You can modify this to generate specific edge cases
    // For example, if you want to test the specific N mentioned in chat:
    // int t = 1; cout << t << endl; cout << 77259 << endl; return 0;

    int t = 5; // Generate 5 test cases per file
    cout << t << endl;

    for(int i = 0; i < t; i++) {
        // Random N between 3 and 2000 (keep it smaller for fast looping, 
        // or increase to 200000 for full stress)
        
        // Occasional large test
        if (rng() % 10 == 0) {
             int n = uniform_int_distribution<int>(50000, 200000)(rng);
             cout << n << endl;
        } else {
             // Mostly small/medium tests for quick iteration
             int n = uniform_int_distribution<int>(3, 500)(rng);
             cout << n << endl;
        }
    }

    return 0;
}