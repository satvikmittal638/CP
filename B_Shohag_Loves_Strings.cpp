#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        
        // Use a set to find distinct characters in `s`
        unordered_set<char> char_set(s.begin(), s.end());
        
        if (char_set.size() == 1) {
            // If there's only one unique character, no valid substring exists
            cout << -1 << '\n';
        } else {
            // Find the first two distinct characters and print their substring
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != s[0]) {
                    cout << s.substr(0, i + 1) << '\n';
                    break;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}