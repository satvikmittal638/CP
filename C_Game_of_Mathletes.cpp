#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    fastio;
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> freq(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            freq[x]++;
        }

        int score = 0;
        for (int x = 1; x <= n; x++) {
            int y = k - x;
            if (y < 1 || y > n) continue;

            if (x == y) {
                score += freq[x] / 2;
                freq[x] %= 2; // Reduce used elements
            } else {
                int pairs = min(freq[x], freq[y]);
                score += pairs;
                freq[x] -= pairs;
                freq[y] -= pairs;
            }
        }

        cout << score << "\n";
    }

    return 0;
}