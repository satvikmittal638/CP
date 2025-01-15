#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()


void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        map<int, int> freq;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            freq[a[i]]++;
        }

        // If we can replace all elements, the result is 1
        if (k >= n) {
            cout << 1 << "\n";
            continue;
        }

        vector<int> freqs;
        for (auto &[key, value] : freq) {
            freqs.push_back(value);
        }

        sort(freqs.begin(), freqs.end());

        int uniqueCount = freqs.size();
        for (int f : freqs) {
            if (k >= f) {
                k -= f;
                uniqueCount--;
            } else {
                break;
            }
        }

        cout << uniqueCount << "\n";
    }
}

int main() {
    fastio
    solve();
    return 0;
}