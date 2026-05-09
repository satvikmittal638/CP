#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

#ifndef ONLINE_JUDGE
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
#else
#define error(args...)
#endif

void solve() {
    int n; ll h;
    cin >> n >> h;
    vector<ll> a(n+1, 0);
    for(int i=1; i<=n; i++) cin >> a[i];

    // pk[i][j]: max height in a[i...j]
    // mp[i][j]: idx of the max height in a[i...j]
    vector<vector<ll>> pk(n+1, vector<ll>(n+1, 0)), mp(n+1, vector<ll>(n+1, 0));
    
    // dpl[i][j]: drained water in cols (i, j] if drain is at i
    // dpr[i][j]: drained water in cols [i, j) if drain is at j
    vector<vector<ll>> dpl(n+1, vector<ll>(n+1, 0)), dpr(n+1, vector<ll>(n+1, 0));

    // peaks and posn
    for(int i=1; i<=n; i++){
        pk[i][i] = a[i];
        mp[i][i] = i;
        for(int j=i+1; j<=n; j++){
            if (a[j] > pk[i][j-1]) {
                pk[i][j] = a[j];
                mp[i][j] = j;
            } else {
                pk[i][j] = pk[i][j-1];
                mp[i][j] = mp[i][j-1];
            }
        }
    }

    // dpl
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            dpl[i][j] = dpl[i][j-1] + (h - pk[i][j]);
        }
    }

    //dpr
    for(int j=1; j<=n; j++){
        for(int i=j-1; i>=1; i--){
            dpr[i][j] = dpr[i+1][j] + (h - pk[i][j]);
        }
    }

    ll ans = 0;

    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            if (i == j) {
                ans = max(ans, dpr[1][i] + dpl[i][n] + (h - a[i]));
                continue;
            }
            
            ll w = dpr[1][i] + dpl[j][n] + (h - a[i]) + (h - a[j]);
            
            // middle 
            if (j > i + 1) {
                int m = mp[i+1][j-1]; 
                w += dpl[i][m] + dpr[m+1][j];
            }
            
            ans = max(ans, w);
        }
    }

    cout << ans << '\n';
}

int main() {
    fastio;
    int tt; cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}