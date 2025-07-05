#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
    fastio;
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> s1(2 * n, 0), s2(2 * n, 0);
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            if (!ok) {
                continue;
            }
            if (a == b) {
                ok = false;
                continue;
            }
            if (s1[a] == 0 && s1[b] == 0) {
                s1[a] = 1;
                s1[b] = 1;
            }
            else if (s2[a] == 0 && s2[b] == 0) {
                s2[a] = 1;
                s2[b] = 1;
            }
            else {
                ok = false;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}