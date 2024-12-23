#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

int main()
{
    fastio;
    vector<int> ctr(32, 0);
    int tt; cin >> tt;
    while (tt--) {
        int t, v; cin >> t >> v;
        if (t == 1) {
            ctr[v]++;
        } else if (t == 2) {
            bool ok = true;
            vector<int> tmp(ctr);
            for (int i = 0; i < 31; i++) {
                if (v & (1 << i)) { // If v requires 2^i
                    if (tmp[i] > 0) {
                        tmp[i]--; // Use one `2^i`
                    } else {
                        ok = false;
                        break;
                    }
                }
                // Transfer excess to next place
                tmp[i+1] += tmp[i] / 2;
                tmp[i] %= 2;
            }
            // for (auto e : tmp) cout << e << " ";
            cout << (ok ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}