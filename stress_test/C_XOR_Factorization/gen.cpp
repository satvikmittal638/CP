#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int main() {
    // Seed with current time
    mt19937 rng(time(0));
    
    int t = 1; // 1 test case per file makes debugging easier
    cout << t << endl;
    
    for (int i = 0; i < t; i++) {
        // Small constraints for effective stress testing
        int n = uniform_int_distribution<int>(1, 1e9)(rng);
        int k = uniform_int_distribution<int>(1, 1e5)(rng);
        cout << n << " " << k << endl;
    }
    return 0;
}