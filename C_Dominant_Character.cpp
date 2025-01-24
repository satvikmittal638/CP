#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

int main()
{
    fastio;
    set<string> ans = {"aa", "aba", "aca", "abca", "acba", "abbacca", "accabba"};
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        int finalAns = 0;

        for (int len = 2; len <= 7; len++) {
            for (int i = 0; i <= n - len; i++) {
                string subs = s.substr(i, len); 
                if (ans.count(subs)) {
                    // cout << subs << " ";
                    finalAns = len;
                    break;
                }
            }
            if (finalAns > 0) break; 
        }

        if (finalAns > 0) 
            cout << finalAns << "\n";
        else 
            cout << "-1\n";
    }
    return 0;
}