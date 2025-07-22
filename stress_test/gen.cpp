#include <bits/stdc++.h>
using namespace std;

int main() {
    const int MAX = 2e5;
    srand(time(0));
    for (int n = 1000; n <= MAX; n += 1000) {
        cout << 1 << "\n"; // one test case per n
        cout << n << "\n";
        for (int i = 0; i < n; ++i)
            cout << (MAX - rand() % 11) << " ";
        cout << "\n";
    }

    return 0;
}