#include <bits/stdc++.h>
using namespace std;

// Function to calculate GCD
int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main(int argc, char* argv[]) {
    // Determine input and output sources
    // Usage: ./validator input_file output_file
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << endl;
        return 1;
    }

    ifstream fin(argv[1]);
    ifstream fout(argv[2]);

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Error opening files." << endl;
        return 1;
    }

    int t;
    if (!(fin >> t)) return 0; // Empty file

    for (int tc = 1; tc <= t; tc++) {
        int n;
        fin >> n;

        vector<int> p(n);
        set<int> unique_elements;
        bool format_error = false;

        for (int i = 0; i < n; i++) {
            if (!(fout >> p[i])) {
                cerr << "[Test " << tc << "] Output ended prematurely." << endl;
                return 1;
            }
            if (p[i] < 1 || p[i] > n) format_error = true;
            unique_elements.insert(p[i]);
        }

        // 1. Check if it's a valid permutation
        if (format_error || unique_elements.size() != n) {
            cerr << "[Test " << tc << "] FAIL: Not a valid permutation of length " << n << endl;
            return 1;
        }

        // 2. Count Bad Indices
        int bad_count = 0;
        vector<int> bad_indices;

        for (int i = 0; i < n - 2; i++) {
            int a = p[i];
            int b = p[i+1];
            int c = p[i+2];

            // Condition: All pairwise GCDs are 1
            if (gcd(a, b) == 1 && gcd(a, c) == 1 && gcd(b, c) == 1) {
                bad_count++;
                bad_indices.push_back(i + 1); // 1-based indexing for reporting
            }
        }

        // 3. Verdict
        if (bad_count > 6) {
            cerr << "[Test " << tc << "] FAIL (N=" << n << "): Found " << bad_count << " bad indices." << endl;
            cerr << "Bad indices at: ";
            for(int idx : bad_indices) cerr << idx << " ";
            cerr << endl;
            return 1;
        } 
    }

    return 0; // Success
}