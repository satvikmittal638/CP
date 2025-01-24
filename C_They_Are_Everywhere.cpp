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
    string s;
    cin >> s;

    set<char> unique_chars(s.begin(), s.end());
    int cnt = unique_chars.size();

    auto isSafe = [&](int k) {
        map<char, int> mp;
        // Process the first window
        for (int j = 0; j < k; j++) {
            mp[s[j]]++;
        }
        if (mp.size() == cnt) return true;

        // Process subsequent windows
        for (int i = 0, j = k; j < n; i++, j++) {
            mp[s[i]]--;
            if (mp[s[i]] == 0) mp.erase(s[i]); // Remove char if count becomes zero
            mp[s[j]]++;
            if (mp.size() == cnt) return true;
        }

        // Check the final window
        return mp.size() == cnt;
    };

    int lo = 1, hi = n, ans = n;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (isSafe(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans;
    return 0;
}