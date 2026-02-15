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

int main()
{
    fastio;
    int tt; cin >> tt;
    while(tt--){
        int n; 
        ll ax, ay, bx, by;
        cin >> n >> ax >> ay >> bx >> by;
        
        vector<ll> x_crd(n), y_crd(n);
        for(int i=0; i<n; i++) cin >> x_crd[i];
        for(int i=0; i<n; i++) cin >> y_crd[i];
        
        map<ll,ll> ymaxByx, yminByx;
        
        ymaxByx[ax] = yminByx[ax] = ay;
        ymaxByx[bx] = yminByx[bx] = by;
        
        for(int i=0; i<n; i++){
            ll x = x_crd[i];
            ll y = y_crd[i];
            
            ymaxByx[x] = max(ymaxByx[x], y);
            
            if(yminByx.find(x) == yminByx.end()){
                yminByx[x] = y;
            } else {
                yminByx[x] = min(yminByx[x], y);
            }
        }
        
        vector<ll> xs;
        for(auto [x, val] : ymaxByx){
            xs.push_back(x);
        }
        
        int m = xs.size();
        
        // dp[i][0] -> min cost to finish processing i-th x-crd ending at max y
        // dp[i][1] -> min cost to finish processing i-th x-crd ending at min y
        vector<vector<ll>> dp(m, vector<ll>(2));
        
        dp[0][0] = 0; 
        dp[0][1] = 0;
        
        for(int i=1; i<m; i++){
            ll prev_x = xs[i-1];
            ll curr_x = xs[i];
            
            ll prev_min = yminByx[prev_x];
            ll prev_max = ymaxByx[prev_x];
            ll curr_min = yminByx[curr_x];
            ll curr_max = ymaxByx[curr_x];
            
            ll dist_range = curr_max - curr_min;
            
            dp[i][0] = min(dp[i-1][0] + abs(prev_max - curr_min) + dist_range, dp[i-1][1] + abs(prev_min - curr_min) + dist_range);
            dp[i][1] = min(dp[i-1][0] + abs(prev_max - curr_max) + dist_range, dp[i-1][1] + abs(prev_min - curr_max) + dist_range);
        }
        
        cout << min(dp[m-1][0], dp[m-1][1]) + (bx - ax) << '\n';
    }
    return 0;
}