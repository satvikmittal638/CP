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
    int tt;cin>>tt;
    while(tt--){
       int n;
    cin >> n;
    vector<ll> a(n);for(auto &i:a) cin>>i;
    /*
    dp(i,j) is ans for [1,i] with j remaining
    now we optimized it
    */
    map<ll, ll> dp;

    dp[a[0]] = 0;
    
    ll offset = 0;
    
    // max_stat tracks max(M[j] + j)
    ll max_stat = dp[a[0]] + a[0];
    
    // max_M tracks max(M[j])
    ll max_M = 0; 

    for (int i = 1; i < n; ++i) {
        ll x = a[i];
        
        // select some prvs j as 1st
        // new Score = (old_offset) + max(M[j] + j)
        ll cand_M_val = max_stat + x;

        // select x as 2nd
        // actual scores decrease by x
        offset -= x;

        if (dp.count(x)) {
            // if x already exists as a survivor state, we keep the max
            dp[x] = max(dp[x], cand_M_val);
        } else {
            dp[x] = cand_M_val;
        }

        // since M[x] only increases or is added, we can just max against current
        max_stat = max(max_stat, dp[x] + x);
        max_M = max(max_M, dp[x]);
    }

    // max(M[j] + offset) = max(M[j]) + offset
    cout << max_M + offset << '\n';
    }
    return 0;
}