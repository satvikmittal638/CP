#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
        int n;cin>>n;
        vector<pair<pair<int,int>,int>> itvl(n);
        for(int i=0;i<n;i++) {
            cin>>itvl[i].first.first>>itvl[i].first.second;
            itvl[i].second=i;
        }
        sort(all(itvl));
        vector<int> ans(n);
        int max_end = itvl[0].first.second;
        int sep_idx = -1;

        for (int i = 1; i < n; ++i) {
            if (itvl[i].first.first > max_end) {
                sep_idx = i;
                break;
            }
            max_end = max(max_end, itvl[i].first.second);
        }

        if (sep_idx == -1) {
            cout << "-1\n";
            continue;
        }

        for (int i = 0; i < sep_idx; ++i)
            ans[itvl[i].second] = 1;
        for (int i = sep_idx; i < n; ++i)
            ans[itvl[i].second] = 2;

        for (auto e : ans) cout << e << " ";
        cout << "\n";
    }
    return 0;
}