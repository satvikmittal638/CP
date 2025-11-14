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
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        ll mx = 0;
        for (int i = 1; i <= n; i++)
        {
            mx = max(mx, a[i]);
            if (i % 2 == 0)
            {
                a[i] = mx;
            }
        }

        ll ans = 0;
        for (int i = 1; i <= n; i += 2)
        {
            ll l = (i > 1) ? a[i - 1] : 2e18;
            ll r = (i < n) ? a[i + 1] : 2e18;

            ll up_bd = min(l, r) - 1;

            if (a[i] > up_bd)
            {
                ans += a[i] - up_bd;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}