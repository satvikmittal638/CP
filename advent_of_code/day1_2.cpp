#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

ll floor_div(ll a, ll b)
{
    ll res = a / b;
    if (a % b != 0 && (a < 0) ^ (b < 0))
    {
        res--;
    }
    return res;
}

int main()
{
    fastio;

    ll cur = 50;
    ll ans = 0;
    string s;
    while (cin >> s)
    {
        int dir = (s[0] == 'L' ? -1 : 1);

        string num_str = s.substr(1);
        if (num_str.back() == ',')
            num_str.pop_back();
        int x = stoi(num_str);

        if (dir == 1)
        {
            //  (cur, cur + x]
            // Count multiples of 100: floor(end/100) - floor(start/100)
            ans += floor_div(cur + x, 100) - floor_div(cur, 100);
        }
        else
        {
            //  [cur - x, cur - 1]
            // Count multiples of 100: floor(end/100) - floor((start - 1)/100)
            ans += floor_div(cur - 1, 100) - floor_div(cur - x - 1, 100);
        }

        cur = cur + dir * x;
        cur = (cur % 100 + 100) % 100;
    }

    cout << ans;
    return 0;
}