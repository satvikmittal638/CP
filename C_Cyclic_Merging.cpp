#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

using E = pair<ll, int>;

int main()
{
    fastio;
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        if (n == 1)
        {
            cout << 0 << '\n';
            continue;
        }

        priority_queue<E, vector<E>, greater<E>> pq;

        vector<int> prev(n), nxt(n);
        vector<bool> active(n, 1);

        for (int i = 0; i < n; ++i)
        {
            pq.push({a[i], i});
            prev[i] = (i == 0) ? (n - 1) : (i - 1);
            nxt[i] = (i == n - 1) ? 0 : (i + 1);
        }

        ll ans = 0ll;
        int mergs = 0;

        while (mergs < n - 1)
        {
            auto [val, cur] = pq.top();
            pq.pop();

            if (!active[cur])
            {
                continue;
            }

            active[cur] = 0;
            mergs++;

            int l = prev[cur];
            int r = nxt[cur];

            if (a[l] <= a[r])
            {
                ans += a[l];
            }
            else
            {
                ans += a[r];
            }
            // deletion like in a circular LL
            nxt[l] = r;
            prev[r] = l;
        }
        cout << ans << '\n';
    }
    return 0;
}