#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
const ll INF = 1e18;
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
        ll orig = 0ll;
        for (int i = 1; i <= n; i++)
        {
            ll val;
            cin >> val;
            if (i % 2 != 0)
            {
                orig += val;
                a[i] = -val; // becomes even on swap
            }
            else
            {
                orig -= val;
                a[i] = val;
            }
        }

        ll delmax = 0ll; // maxm possible change in score

        // same parity swaps
        delmax = n - 1 - (n % 2 == 0);

        // maximize and minimize this : (2*a[r]+r) + (2*a[l]-l)
        // mx will track max(2*a[l]-l) for odd l
        ll mx = -INF;
        // mn will track max(2*a[l]-l) for even l
        ll mn = -INF;

        for (int r = 1; r <= n; r++)
        {
            ll cur = 2 * a[r] + r;

            if (r % 2 != 0)
            {
                if (mn != -INF)
                {
                    delmax = max(delmax, cur + mn);
                }
            }
            else
            {
                if (mx != -INF)
                {
                    delmax = max(delmax, cur + mx);
                }
            }

            // update the tracker
            if (r % 2 != 0)
            {
                mx = max(mx, 2 * a[r] - r);
            }
            else
            {
                mn = max(mn, 2 * a[r] - r);
            }
        }

        cout << orig + delmax << '\n';
    }
    return 0;
}