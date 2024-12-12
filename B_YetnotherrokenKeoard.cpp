#include <iostream>
#include <deque>
#include <cctype> // for isupper() and islower()
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // Deques to store characters and their indices
        deque<pair<int, char> > dC, dS; 
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'b') {
                if (!dS.empty()) {
                    dS.pop_back();
                }
            } else if (s[i] == 'B') {
                if (!dC.empty()) {
                    dC.pop_back();
                }
            } else {
                if (isupper(s[i])) {
                    dC.push_back(make_pair(i, s[i]));
                } else if (islower(s[i])) {
                    dS.push_back(make_pair(i, s[i]));
                }
            }
        }

        // Output the resulting string
        while (!dC.empty() || !dS.empty()) {
            if (dC.empty()) {
                cout << dS.front().second;
                dS.pop_front();
            } else if (dS.empty()) {
                cout << dC.front().second;
                dC.pop_front();
            } else if (dC.front().first < dS.front().first) {
                cout << dC.front().second;
                dC.pop_front();
            } else {
                cout << dS.front().second;
                dS.pop_front();
            }
        }
        cout << endl;
    }

    return 0;
}