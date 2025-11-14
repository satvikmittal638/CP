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
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<vector<int>> a(2, vector<int>(n));
        for (int i = 0; i < n; i++)
            cin >> a[0][i];
        for (int i = 0; i < n; i++)
            cin >> a[1][i];

        int N = 2 * n; // The max possible value is 2n

        vector<int> pre_min_1(n), pre_max_1(n);
        pre_min_1[0] = pre_max_1[0] = a[0][0];
        for (int k = 1; k < n; k++)
        {
            pre_min_1[k] = min(pre_min_1[k - 1], a[0][k]);
            pre_max_1[k] = max(pre_max_1[k - 1], a[0][k]);
        }

        vector<int> suf_min_2(n), suf_max_2(n);
        suf_min_2[n - 1] = suf_max_2[n - 1] = a[1][n - 1];
        for (int k = n - 2; k >= 0; k--)
        {
            suf_min_2[k] = min(suf_min_2[k + 1], a[1][k]);
            suf_max_2[k] = max(suf_max_2[k + 1], a[1][k]);
        }

        // L_k = min value on path k
        // R_k = max value on path k
        vector<pair<int, int>> path_reqs(n);
        for (int k = 0; k < n; k++)
        {
            int L_k = min(pre_min_1[k], suf_min_2[k]);
            int R_k = max(pre_max_1[k], suf_max_2[k]);
            path_reqs[k] = {L_k, R_k};
        }

        // R_min[l] will store the minimum r required if we pick l
        vector<int> R_min(N + 2, N + 1);

        // l_to_R[l] will store all R_k values for paths where L_k = l
        vector<vector<int>> l_to_R(N + 2);
        for (int k = 0; k < n; k++)
        {
            int L_k = path_reqs[k].first;
            int R_k = path_reqs[k].second;
            l_to_R[L_k].push_back(R_k);
        }

        int cur_min_R = N + 1; //active min R
        for (int l = N; l >= 1; l--)
        {
            for (int R_k : l_to_R[l])
            {
                cur_min_R = min(cur_min_R, R_k);
            }
            R_min[l] = cur_min_R;
        }

        ll ans = 0;
        for (int l = 1; l <= N; l++)
        {
            // r >= l
            // r >= R_min_array[l]

            int r_start = max(l, R_min[l]);

            if (r_start <= N)
            {
                ans += (N - r_start + 1);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}