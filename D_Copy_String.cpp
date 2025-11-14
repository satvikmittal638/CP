#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
int main()
{
    fastio;
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, kmax;
        cin >> n >> kmax;
        string s, t;
        cin >> s >> t;

        // dp[c][j] = rightmost index <= j where s[idx] == c
        vector<vector<int>> dp(26, vector<int>(n, -1));
        for (int c = 0; c < 26; c++)
            dp[c][0] = ((s[0] - 'a') == c ? 0 : -1);
        for (int j = 1; j < n; j++)
            for (int c = 0; c < 26; c++)
                dp[c][j] = ((s[j] - 'a') == c ? j : dp[c][j - 1]);

        bool pos = 1;
        int need = 0;
        for (int i = 0; i < n; i++)
        {
            int c = t[i] - 'a';
            int j = dp[c][i];
            if (j == -1)
            {
                pos = 0;
                break;
            }
            need = max(need, i - j);
        }

        if (!pos || need > kmax)
        {
            cout << -1 << "\n";
            continue;
        }

        cout << need << "\n";
        for (int step = 0; step < need; step++)
        {
            string ns = s;
            for (int i = 1; i < n; i++)
                ns[i] = (s[i] == t[i]) ? s[i] : ((s[i - 1] == t[i]) ? s[i - 1] : s[i]);
            s = ns;
            cout << s << "\n";
            if (s == t)
                break;
        }
    }
    return 0;
}