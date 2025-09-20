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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // global counts
        vector<int> cnt(n + 1, 0);
        for (int v : a) cnt[v]++;

        // Max quota of each value per multiset
        bool ok=1;
        vector<int> mx(n + 1, 0);
        for (int v = 1; v <= n; v++)
        {
            if(cnt[v]%k!=0){
                ok=0;
                break;
            }
            mx[v] = cnt[v] / k;
        }
        if(!ok){
            cout<<"0\n";
            continue;
        }
        vector<int> freq(n+1,0); // maintains running frequency
        ll ans = 0ll;
        int l = 0;
        for (int r = 0; r < n; r++)
        {
            freq[a[r]]++;
            while (freq[a[r]] > mx[a[r]])
            {
                freq[a[l]]--;
                l++;
            }
            ans += (r - l + 1); // for a given r, all values of l before it works
        }
        cout << ans << "\n";
    }
    return 0;
}