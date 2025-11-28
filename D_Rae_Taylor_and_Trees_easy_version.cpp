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
        vector<int> p(n);
        for (auto &x : p)
            cin >> x;

        vector<int> sufMax(n);
        sufMax[n - 1] = p[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            sufMax[i] = max(sufMax[i + 1], p[i]);
        }

        int preMin = p[0];
        bool ok = 1;

        for (int i = 0; i < n - 1; i++)
        {
            preMin = min(preMin, p[i]);
            if (preMin > sufMax[i + 1])
            {
                ok = 0;
                break;
            }
        }

        cout << (ok ? "Yes" : "No") << '\n';
    }
    return 0;
}