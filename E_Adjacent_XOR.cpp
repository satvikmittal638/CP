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
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        if (a[n - 1] != b[n - 1]) {
            cout << "NO\n";
            continue;
        }

     
        bool bwd_pos = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (b[i] != a[i] && b[i]!=(a[i]^a[i+1]) && b[i] != (a[i] ^ b[i + 1])) {
                bwd_pos = 0;
                break;
            }
        }

        if (bwd_pos) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}