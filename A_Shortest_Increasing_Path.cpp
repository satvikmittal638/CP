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
        ll x, y;
        cin >> x >> y;

        int ans = -1;
        if (y > x)
        {
            ans = 2;
        }
        else if (x > y + 1 && y >= 2)
        {
            ans = 3;
        }
        else
        {
            ans = -1;
        }

        cout << ans << "\n";
    }
    return 0;
}