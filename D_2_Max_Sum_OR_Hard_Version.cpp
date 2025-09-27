#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
vector<int> p;

// let build(r) build the array a[0,r]
void build(int l,int r)
{
    if (r < l) return;
    // base
    if (r == l)
    {
        p[0] = l;
        return;
    }

    // find the smallest k such that 2^k > r
    int k = 0;
    while ((1 << k) <= r)
    {
        k++;
    }
    int mask = (1 << k) - 1;// 11..1 k set bits and length k

    int split = mask ^ r;

    // pair no.s from split to r
    for (int i = split-l; i <= r; ++i)
    {
        p[i] = mask ^ i;// bitwise complement-> &=0
    }

    build(l,split - 1);
}

int main()
{
    fastio;
    int tt;
    cin >> tt;
    while (tt--)
    {
        int l, r;
        cin >> l >> r;

        ll n = r - l + 1;
        ll ans = (ll)r * (r + 1);

        cout << ans << "\n";

        p.assign(n, 0);
        build(l,r);

        for (int i = 0; i < n; ++i)
        {
            cout << p[i] << ' ';
        }
        cout << "\n";
    }
    return 0;
}