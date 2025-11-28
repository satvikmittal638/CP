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
        ll a, b, n;
        cin >> a >> b >> n;
        if (a == b)
        {
            cout << 1 << '\n';
            continue;
        }
        ll k = a / b;
        if (n <= k)
            cout << 1 << '\n';
        else
            cout << 2 << '\n';
    }
    return 0;
}