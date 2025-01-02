#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
    fastio;
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector<ll> p_ab(n + 1, 0ll);
    for (int i = 1; i <= n; i++) {
        p_ab[i] = p_ab[i - 1] + a[i] * b[i];
    }
    ll ans = 0ll;
    for (int k = 2; k <= 2 * n; k++) {
        vector<ll> p_rev_ab(n + 1, 0ll);
        // l + r = k
        for (int i = 1; i <= n; i++) {
            if (k - i >= 1 && k - i <= n) {
                p_rev_ab[i] = p_rev_ab[i - 1] + a[i] * b[k - i];
            }
        }
        for (int l = max(1, k - n), r = min(n, k - 1); l <= r; l++, r--) {
            ll curSum = (p_ab[l - 1]) + (p_rev_ab[r] - p_rev_ab[l - 1]) + (p_ab[n] - p_ab[r]);
            ans = max(ans, curSum);
        }
    }
    ans = max(ans, p_ab[n]); // No reverse
    cout << ans;
    return 0;
}