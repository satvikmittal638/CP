#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

int main() {
    fastio;
    ll n, xo, yo;
    cin >> n >> xo >> yo;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    set<pair<ll, ll>> st; // Store reduced slopes as pairs
    for (int i = 0; i < n; i++) {
        ll dx = x[i] - xo;
        ll dy = y[i] - yo;
        if (dx == 0) {
            st.insert({1, 0}); // Vertical line
        } else if (dy == 0) {
            st.insert({0, 1}); // Horizontal line
        } else {
            ll g = gcd(dx, dy);
            dx /= g;
            dy /= g;
            if (dx < 0) { // Ensure unique representation
                dx = -dx;
                dy = -dy;
            }
            st.insert({dx, dy});
        }
    }

    cout << st.size();
    return 0;
}