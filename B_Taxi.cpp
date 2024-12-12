#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> groups(5, 0); // Index 1 to 4 represent group sizes
    
    for (int i = 0; i < n; ++i) {
        int size;
        cin >> size;
        groups[size]++;
    }

    int taxis = 0;

    // Groups of size 4 need separate taxis
    taxis += groups[4];

    // Groups of size 3 can pair with groups of size 1
    taxis += groups[3];
    groups[1] = max(0, groups[1] - groups[3]);

    // Two groups of size 2 can share a taxi
    taxis += groups[2] / 2;
    if (groups[2] % 2 == 1) {
        taxis++; // One taxi for the remaining group of size 2
        groups[1] = max(0, groups[1] - 2); // Pair it with up to two groups of size 1
    }

    // Remaining groups of size 1 need taxis
    taxis += (groups[1] + 3) / 4; // Group them in taxis of size 4

    cout << taxis << endl;

    return 0;
}