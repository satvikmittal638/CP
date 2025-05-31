#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

int main() {
    fastio;
    int n; cin >> n;
    string s, t; cin >> s >> t;
    vector<int> ab, ba;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a' && t[i] == 'b') ab.push_back(i + 1);
        else if (s[i] == 'b' && t[i] == 'a') ba.push_back(i + 1);
    }
    int x = ab.size(), y = ba.size();
    if ((x + y) % 2 != 0) {
        cout << -1;
        return 0;
    }
    if (x + y == 0) {
        cout << 0;
        return 0;
    }
    int k = (x + y) / 2 + (x % 2);
    cout << k << "\n";
    
    // Process ab pairs
    for (int i = 0; i + 1 < ab.size(); i += 2) {
        cout << ab[i] << " " << ab[i + 1] << "\n";
    }
    // Process ba pairs
    for (int i = 0; i + 1 < ba.size(); i += 2) {
        cout << ba[i] << " " << ba[i + 1] << "\n";
    }
    // Handle remaining ab and ba
    if (x % 2 == 1 && y % 2 == 1) {
        int i = ab.back();
        int j = ba.back();
        cout << i << " " << i << "\n";
        cout << i << " " << j << "\n";
    }
    return 0;
}