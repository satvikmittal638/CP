#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
    fastio;
    int tt; cin >> tt;
    while (tt--) {
        ll a, b; cin >> a >> b;
        string s; cin >> s;
        int n = s.length();
        int l = 0, r = n - 1;

        // Skip leading 0s
        while (l < n && s[l] == '0') l++;
        // Skip trailing 0s
        while (r > l && s[r] == '0') r--;

        // If no '1's exist, result is 0
        if (l > r) {
            cout << "0\n";
            continue;
        }

        vector<int> dist;
        for (int i = l; i <= r;) {
            int d = 0;
            while (i <= r && s[i] == '1') i++;
            while (i <= r && s[i] == '0') i++, d++;
            if (d > 0)
                dist.push_back(d);
        }

        ll ans = 0;
        int totalSegs = dist.size() + 1;

        for (int i = 0; i < dist.size(); i++) {
            if (b * dist[i] <= a) {
                // Merge 2 adjacent segments
                ans += b * dist[i];
                totalSegs--;
            }
        }

        ans += totalSegs * a; // Blast all the segments
        cout << ans << "\n";
    }
    return 0;
}