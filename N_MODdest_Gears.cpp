#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

int main() {
    fastio;
    int a, b, k;
    cin >> a >> b >> k;
    
    vector<int> fib(1e6 + 1);
    fib[0] = a;
    fib[1] = b;

    // Generate the Fibonacci-like sequence modulo k
    for (int i = 2; i <= 1e6; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % k;
    }

    int segment_end = -1, sum = 0;

    // Find the repeating cycle in the Fibonacci sequence
    for (int i = 2; i < 1e6 - 1; i++) {
        sum += fib[i];

        if (i + 2 < 1e6 && fib[i + 1] == a && fib[i + 2] == b) {
            segment_end = i; // This is where the sequence repeats
            break;
        }
    }

    // Handle queries
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;

        // Find how many full cycles fit into x
        int cutAt = (x / sum) * segment_end;
        x %= sum;

        // Find the position of x within the remaining sum
        int curSum = 0, i = 0;
        while (curSum < x) {
            curSum += fib[i];
            i++;
        }

        cutAt += i;
        cout << cutAt << "\n";
    }

    return 0;
}