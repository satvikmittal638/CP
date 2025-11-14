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
        ll k;
        cin >> n >> k;

        if (k == (ll)n * n - 1)
        {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        vector<vector<char>> ans(n, vector<char>(n));

        int p = k / n;
        int r = k % n;

        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans[i][j] = 'L';
            }
        }

        for (int i = p; i < n; i++)
        {
            ans[i][0] = 'R';
            for (int j = 1; j < n; j++)
                ans[i][j] = 'L';
        }

        if (r > 0 && p < n)
        {
            if (r == n - 1)
            {
                for (int j = 0; j < n - 1; j++)
                {
                    ans[p][j] = 'L';
                }
                ans[p][n - 1] = 'D';
            }
            else
            {
                for (int j = 0; j < r; j++)
                {
                    ans[p][j] = 'L';
                }
                ans[p][r] = 'R';
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << ans[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}