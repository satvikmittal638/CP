#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

#ifndef ONLINE_JUDGE
#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }

void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
#else
#define error(args...)
#endif

int main()
{
    fastio;
    int tt;
    cin >> tt;
    while (tt--)
    {
        ll n, x, y;
        cin >> n >> x >> y;
        string s;
        cin >> s;
        vector<ll> p(n);
        for (auto &i : p)
            cin >> i;
        bool ok = 1;
        for (int i = 0; i < n; i++)
        {
            // ll del=abs(x-y);
            // a[i]>b[i]
            ll a, b;
            if (s[i] == '0')
            {
                // mistake 1: find winner's share first
                a = p[i] / 2 + 1, b = p[i] - a;
            }
            // b[i]>a[i]
            else
            {
                b = p[i] / 2 + 1, a = p[i] - b;
            }
            x -= a;
            y -= b;
        }
        if (x < 0 || y < 0)
        {
            cout << "NO\n";
            continue;
        }
        // can I use up extra votes?
        int cntA = count(all(s), '0'), cntB = n - cntA;
        // Case 1: Mixed winners. We can always dump extra votes into their respective winning districts.
        if (cntA > 0 && cntB > 0)
        {
            cout << "YES\n";
        }
        // Mistake 2: can give 1 to both a and b to maintain inequality

        // Case 2: A wins everywhere.
        // We can dump extra 'x' freely.
        // To dump extra 'y', we must match them with 'x' to maintain a > b.
        else if (cntB == 0)
        {
            if (x >= y)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        // Case 3: B wins everywhere.
        else
        {
            if (y >= x)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}