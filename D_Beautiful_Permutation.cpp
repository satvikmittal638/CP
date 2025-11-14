#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

int main()
{
    fastio;
    int tt;
    cin >> tt;
    while (tt--)
    {
        ll n;
        cin >> n;

        cout << "2 1 " << n << endl;
        ll x;
        cin >> x;

        ll c = x - (n * (n + 1) / 2);

        ll lo = 1, hi = n;
        while (lo < hi)
        {
            ll mid = (lo + hi) / 2;

            cout << "1 1 " << mid << endl;
            ll x1;
            cin >> x1;

            cout << "2 1 " << mid << endl;
            ll x2;
            cin >> x2;

            ll dif = x2 - x1;

            if (dif == 0)
                lo = mid + 1;
            else
                hi = mid;
        }

        cout << "! " << lo << " " << lo + c - 1 << endl;
        cout.flush();
    }
    return 0;
}