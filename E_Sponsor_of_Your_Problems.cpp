#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main() {
    fastio;

    int t;
    cin >> t;
    vector<string> results;

    while (t--) {
        string l_str, r_str;
        cin >> l_str >> r_str;
        int n = l_str.size();
        vector<int> L(n);
        vector<int> R(n);
        for (int i = 0; i < n; i++) {
            L[i] = l_str[i] - '0';
            R[i] = r_str[i] - '0';
        }

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(2, INT_MAX)));

        for (int tl = 0; tl < 2; tl++) {
            for (int tr = 0; tr < 2; tr++) {
                dp[n][tl][tr] = 0;
            }
        }

        for (int pos = n-1; pos >= 0; pos--) {
            for (int tl = 0; tl < 2; tl++) {
                for (int tr = 0; tr < 2; tr++) {
                    int lo_bound = (tl ? L[pos] : 0);
                    int hi_bound = (tr ? R[pos] : 9);
                    int best = INT_MAX;

                    for (int d = lo_bound; d <= hi_bound; d++) {
                        int new_tl = (tl && (d == L[pos])) ? 1 : 0;
                        int new_tr = (tr && (d == R[pos])) ? 1 : 0;

                        int cost_here;
                        if (L[pos] == R[pos]) {
                            cost_here = (d == L[pos]) ? 2 : 0;
                        } else {
                            if (d == L[pos] || d == R[pos]) {
                                cost_here = 1;
                            } else {
                                cost_here = 0;
                            }
                        }

                        int next_val = dp[pos+1][new_tl][new_tr];
                        if (next_val != INT_MAX) {
                            int total = cost_here + next_val;
                            if (total < best) {
                                best = total;
                            }
                        }
                    }

                    dp[pos][tl][tr] = best;
                }
            }
        }

        results.push_back(to_string(dp[0][1][1]));
    }

    for (const string& res : results) {
        cout << res << '\n';
    }

    return 0;
}