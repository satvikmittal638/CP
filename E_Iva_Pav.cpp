#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

int main() {
    fastio;
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<vector<int>> pref(32, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            for (int j = 0; j < 32; j++) {
                pref[j][i] = pref[j][i - 1] + (((1 << j) & a) != 0);
            }
        }

        int q;
        cin >> q;
        while (q--) {
            int l, k;
            cin >> l >> k;
            int lo=l,hi=n,ans=-1;
            // f(l,r) is an non-increasing function for increasing r
            // so BS can be used
            while(lo<=hi){
                int mid=(lo+hi)/2;
                // compute f(l,mid)
                int num=0;
                for(int i=0;i<32;i++){
                    if(pref[i][mid]-pref[i][l-1]==mid-l+1)
                        num+=(1<<i);
                }
                if(num>=k){
                    lo=mid+1;
                    ans=max(ans,mid);
                }
                else hi=mid-1;
                
            }
            cout<<ans<<" ";
        }
        cout << "\n";
    }
    return 0;
}