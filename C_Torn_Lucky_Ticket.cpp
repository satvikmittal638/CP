#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

// TODO: some issue in implementation
int main() {
    fastio;
    const int MAX_L = 10, MAX_S = 90;
    int n;
    cin >> n;

    // cnt[l][s] denotes no. of numbers with length l and sum s
    vector<string> s(n);
    vector<vector<int>> cnt(MAX_L + 1, vector<int>(MAX_S + 1, 0));

    auto digSum = [](string s) {
        int sum = 0;
        for (auto c : s) {
            sum += c - '0';
        }
        return sum;
    };

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        cnt[s[i].length()][digSum(s[i])]++;
    }

    for (int i = 0; i <= MAX_L; i++) {
        for (int j = 0; j <= MAX_S; j++) {
            if (cnt[i][j] > 0) {
                cout << "cnt[" << i << "][" << j << "] = " << cnt[i][j] << endl;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int len = s[i].length();
        for (int l = len+(len%2); l <= MAX_L; l += 2) {
            // 1st part is longer
            if (l / 2 <= len) {
                int suml = digSum(s[i].substr(0, l / 2));
                int sumr = digSum(s[i].substr(l / 2));
                if (suml - sumr >= 0) {
                    ans += cnt[l][suml - sumr];
                }
            }
            // 2nd part is longer (strictly)
            int prefEnd = len - l / 2;
            if(prefEnd>=0){
                int suml = digSum(s[i].substr(0, prefEnd));
                int sumr = digSum(s[i].substr(prefEnd));
                if (sumr - suml >= 0) {
                    ans += cnt[l][sumr - suml];
                }
            }

        }
    }

    cout << ans;
    return 0;
}