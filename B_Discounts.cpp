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
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(k);
        for (auto &i : a)
            cin >> i;
        for (auto &i : b)
            cin >> i;
        sort(rall(a));
        sort(all(b));
        int j = 0;
        ll ans = 0ll;
        for (auto x : b)
        {
            // pay for first (x-1) items
            for (int cnt = 0; cnt < x - 1 && j < n; cnt++)
            {
                ans += a[j++];
            }
            // skip one free item if available
            if (j < n)
                j++;
        }
        while(j<n) ans+=a[j++];
        cout << ans << '\n';
    }
    return 0;
}