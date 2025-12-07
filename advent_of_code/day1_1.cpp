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
    int cur = 50, ans = 0;
    string s;
    while (cin >> s)
    {
        int dir = (s[0] == 'L' ? -1 : 1);
        int x = stoi(s.substr(1));
        cur = cur + dir * x;
        cur = (cur + 100) % 100;
        ans += cur == 0;
    }
    cout << ans;
    return 0;
}