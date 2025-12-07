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
        int n, l, r;
        cin >> n >> l >> r;

        vector<ll> p(n + 1);
        for (int i = 0; i <= n; i++)
            p[i] = i;
        p[r] = l - 1;

        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            a[i] = p[i - 1] ^ p[i];
            if (a[i] == 0)
                a[i] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}