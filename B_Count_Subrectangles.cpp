#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
    fastio;
    int n,m,k; cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    
    auto countRects = [&](int h, int w){
        // find number of subsegments of a with h consecutive 1s
        ll cntA = 0ll;
        int sum = 0;
        for(int l = 0, r = 0; r < n; r++) {
            sum += a[r]; 
            
            if(r - l + 1 == h) {
                if(sum == h) cntA++; 
                sum -= a[l]; 
                l++;
            }
        }

        // find number of subsegments of b with w consecutive 1s
        ll cntB = 0ll;
        sum = 0;
        for(int l = 0, r = 0; r < m; r++) {
            sum += b[r]; 
            
            if(r - l + 1 == w) {
                if(sum == w) cntB++; 
                sum -= b[l];
                l++;
            }
        }
        return cntA * cntB;
    };

    ll ans = 0ll;
    for(int d = 1; d * d <= k; d++) {
        if(k % d == 0) {
            int d2 = k / d;
            ans += countRects(d, d2);
            if(d != d2) ans += countRects(d2, d);
        }
    }
    cout << ans;
    return 0;
}