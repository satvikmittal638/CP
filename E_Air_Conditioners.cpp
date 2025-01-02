#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
    const int INF=INT_MAX;
    fastio;
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(k), t(k);
        for (auto &i : a) cin >> i;
        for (auto &i : t) cin >> i;

        vector<int> t_sub_a(n + 1, INF), t_add_a(n + 1, INF);
        for (int i = 0; i < k; i++) {
            t_sub_a[a[i]] = t[i] - a[i];
            t_add_a[a[i]] = t[i] + a[i];
        }

        vector<int> p_min(n + 1, INF), s_min(n + 2, INF);
        for (int i = 1; i <= n; i++) {
            p_min[i] = min(p_min[i - 1], t_sub_a[i]);
        }
        for (int i = n; i >= 1; i--) {
            s_min[i] = min(s_min[i + 1], t_add_a[i]);
        }

        for (int i = 1; i <= n; i++) {
            cout << min(p_min[i]==INT_MAX?INT_MAX:(p_min[i] + i),s_min[i]==INT_MAX?INT_MAX:(s_min[i] - i)) << " ";
            // cout<<p_min[i]<<" ";
        }
        // cout<<"\n"; 
        // for (int i = 1; i <= n; i++) {
        //     // cout << min(p_min[i] + i, s_min[i] - i) << " ";
        //     cout<<s_min[i]<<" ";
        // }
        cout << "\n";
    }
    return 0;
}