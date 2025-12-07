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
        map<int, int> cnt;
        for (int i = 0; i < 2 * n; i++)
        {
            int x;
            cin >> x;
            cnt[x]++;
        }

        int odd_cnts = 0,even_cnts = 0;

        for (auto &[val, count] : cnt)
        {
            if (count % 2 != 0)
                odd_cnts++;
            else
                even_cnts++;
        }

        int ans = odd_cnts + 2 * even_cnts;

    
        if (odd_cnts == 0)
        {
            if (even_cnts % 2 != n % 2)
            {
                ans -= 2;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}