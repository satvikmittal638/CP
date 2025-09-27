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
        int n;
        cin >> n;
        string s;
        cin >> s;

        bool ok = 1;
        if ((s[0] == '0' && s[1] == '1') || (s[n - 2] == '1' && s[n - 1] == '0'))
        {
            ok = 0;
        }
        for (int i = 0; i < n - 2; i++)
        {
            if (s[i] == '1' && s[i + 1] == '0' && s[i + 2] == '1')
            {
                ok = 0;
                break;
            }
        }

        if (!ok)
        {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        vector<int> ans(n);
        iota(ans.begin(), ans.end(), 1);

        int i = 0;
        while (i < n)
        {
            if (s[i] == '1')
            {
                i++;
                continue;
            }
            // find end of block of 0s
            int j = i;
            while (j + 1 < n && s[j + 1] == '0')
            {
                j++;
            }
            // block of 0s is from i to j.
            reverse(ans.begin() + i, ans.begin() + j + 1);

            i = j + 1;
        }

        for (int k = 0; k < n; ++k)
        {
            cout << ans[k] << ' ';
        }
        cout << "\n";
    }
    return 0;
}