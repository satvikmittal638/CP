#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

int main() {
    fastio;
    ll tt;
    cin >> tt;
    while(tt--){
        ll n, m;
        cin >> n >> m;
        vector<ll> k(n);
        for(auto &i:k) cin >> i;
        sort(all(k));

        auto f = [](ll a, ll b, ll c, ll k) {
            return (b - k) * (b - k) - 4 * a * c;
        };

        for(ll i = 0; i < m; i++) {
            ll a, b, c;
            cin >> a >> b >> c;

            // Finding the poll where nature changes
            auto it = lower_bound(all(k), b); 
            ll ind = it - k.begin();

            if(ind>0 && f(a,b,c,k[ind-1])<0) {
                cout<<"YES\n"<<k[ind-1]<<"\n";
                continue;
            }
            if(ind<n && f(a,b,c,k[ind])<0) {
                cout<<"YES\n"<<k[ind]<<"\n";
                continue;
            }
            cout<<"NO\n";
        }
    }
    return 0;
}