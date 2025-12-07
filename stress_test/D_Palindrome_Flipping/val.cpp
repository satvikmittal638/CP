#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// Helper function
bool isPalin(const string& s, int l, int r){
    while(l < r){
        if(s[l] != s[r]) return 0;
        l++; r--;
    }
    return 1;
}

int main(int argc, char* argv[]) {
    fastio;    
    ifstream inp(argv[1]);  // Input file
    ifstream out(argv[2]);  // User Output file

    // Check if files opened successfully
    if (!inp || !out) {
        cerr << "Error: Could not open input or output files." << endl;
        return 1;
    }

    int t;
    if (!(inp >> t)) return 0; // Handle empty input files gracefully

    for (int i = 1; i <= t; i++) {
        int n;
        string s, target;
        inp >> n >> s >> target;

        int k; 
        if (!(out >> k)) {
            cerr << "Test " << i << ": Output format error (could not read k)" << endl;
            return 1;
        }

        // Handle the "Impossible" case
        if (k == -1) {
            // If you know a solution exists (because of your generator), -1 is Wrong Answer.
            // If the test could actually be impossible, you'd need a solver here to verify.
            // Assuming for this specific problem (Constructive), we expect a solution:
            cerr << "Test " << i << ": User output -1 (claimed impossible)." << endl;
            return 1; 
        }

        if(k > 2 * n){
            cerr << "Test " << i << ": Too many operations (" << k << " > " << 2*n << ")" << endl;
            return 1;
        }

        // Read operations
        for(int op = 0; op < k; op++) {
            int l, r;
            // CRITICAL FIX: Use 'out', not 'cin'
            out >> l >> r; 
            
            l--; r--; // Convert to 0-indexed

            // Bounds check
            if(l < 0 || r >= n || l > r){
                cerr << "Test " << i << ": Invalid index range [" << l+1 << ", " << r+1 << "]" << endl;
                return 1;
            }

            // Palindrome check
            if(!isPalin(s, l, r)){
                cerr << "Test " << i << ": Range [" << l+1 << ", " << r+1 << "] is NOT a palindrome." << endl;
                cerr << "String state: " << s << endl;
                return 1;
            }

            // Simulate
            for(int j = l; j <= r; j++){
                s[j] = (s[j] == '0' ? '1' : '0');
            }
        }

        if(s != target){
            cerr << "Test " << i << ": Result string does not match target." << endl;
            cerr << "Expected: " << target << endl;
            cerr << "Got:      " << s << endl;
            return 1;
        }
        
        // Optional: Only print success for debugging, otherwise silence is golden
        // cerr << "Test " << i << " Passed" << endl; 
    }

    cerr << "OK: All test cases passed!" << endl;
    return 0;
}