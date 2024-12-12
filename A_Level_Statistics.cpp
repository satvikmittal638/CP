#include<bits/stdc++.h>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int prevp = -1, prevc = -1; 
        bool ok = true;
        while (n--) {
            int p, c;
            cin >> p >> c;
            if (p < c || p < prevp || c < prevc || (p - prevp) < (c - prevc)) {
                ok = false;
            }
            prevp = p;
            prevc = c;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}