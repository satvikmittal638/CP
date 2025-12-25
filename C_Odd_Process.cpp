#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

void solve()
{
    int n;
    cin >> n;
    vector<ll> odds, evens;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x % 2 != 0)
            odds.push_back(x);
        else
            evens.push_back(x);
    }

    sort(rall(odds));
    sort(rall(evens));

    int cnt_ev = evens.size(), cnt_od = odds.size();
    vector<ll> pref_ev(cnt_ev + 1, 0);
    for (int i = 0; i < cnt_ev; i++)
    {
        pref_ev[i + 1] = pref_ev[i] + evens[i];
    }

    for (int k = 1; k <= n; k++)
    {
        // if no odd numbers exist, sum is always even (0) or empty
        if (cnt_od == 0)
        {
            cout << "0 ";
            continue;
        }

        ll ans = 0;

        // enough room in 'k' to take 1 odd and the rest evens.
        // prioritize taking the largest odd and the largest (k-1) evens.
        if (k - 1 <= cnt_ev)
        {
            ans = odds[0] + pref_ev[k - 1];
        }
        // must take all evens, and fill the rest with odds
        else
        {
            int evens_to_take = cnt_ev;
            int odds_needed = k - cnt_ev;

            // If the number of odds needed is Even, the total sum parity would be Even -> 0.
            // fix this by dropping 1 even and adding 1 more odd
            if (odds_needed % 2 == 0)
            {
                evens_to_take--;
                odds_needed++;
            }

            if (evens_to_take >= 0 && odds_needed <= cnt_od)
            {
                ans = odds[0] + pref_ev[evens_to_take];
            }
            else
            {
                ans = 0;
            }
        }
        cout << ans << " ";
    }
    cout << "\n";
}

int main()
{
    fastio;
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}