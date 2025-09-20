#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int ask(int a, int b, int c) {
    cout << "? " << a << " " << b << " " << c << endl;
    int res;
    cin >> res;
    if (res == -1) exit(0);
    return res;
}

int main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> tri = {1, 2, 3};

        while (1) {
            bool changed = 0;
            for (int i = 0; i < 3; i++) {
                int inside = ask(tri[0], tri[1], tri[2]);
                if (inside != 0) {
                    int idx = rand() % 3;
                    tri[idx] = inside;
                    changed = 1;
                    break; // after replacement, restart checking
                }
            }
            if (!changed) break; // no replacements = triangle is empty
        }

        cout << "! " << tri[0] << " " << tri[1] << " " << tri[2] << endl;
    }
    return 0;
}