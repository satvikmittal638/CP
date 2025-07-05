#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main() {
    fastio;
    int tt;
    cin >> tt;
    while (tt--) {
    string s;
    cin >> s;
    ll pos;
    cin >> pos;
    int n = s.length();

         // find index of string(1-based) pos lies in
       int ind_s=1;
       while(pos>n*ind_s-(ind_s*(ind_s-1))/2) ind_s++; // O(1e3)
       pos -= (ind_s - 1) * n - ((ind_s - 1) * (ind_s - 2)) / 2;   // adjust pos within that string
       pos--; // make 0-indexed

        stack<char> st;
        int l = 0, r = n - 1;

        while (ind_s && l <= r) {
            // remove larger elements to push s[l]
            while (ind_s && !st.empty() && l <= r && st.top() > s[l]) {
                st.pop();
                ind_s--;
            }
            st.push(s[l]);
            l++;
        }

        // remove from end if more deletions remain
        while (ind_s && r >= l) {
            r--;
            ind_s--;
        }

        string final_s;
        while (!st.empty()) {
            final_s.push_back(st.top());
            st.pop();
        }
        reverse(all(final_s));
        for (int i = l; i <= r; i++) {
            final_s.push_back(s[i]);
        }

        cout << final_s[pos];
    }
    return 0;
}