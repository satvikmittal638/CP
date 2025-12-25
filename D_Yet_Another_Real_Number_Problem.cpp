#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll MOD=1e9+7;

ll modexp(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int main()
{
    fastio;
    ll tt; cin >> tt;
    while(tt--){
       int n; cin >> n;
       stack<pair<ll,ll>> st; // {odd part (q), no. of 2 divisors (p)}
       ll sum = 0ll;
       
       for(ll i = 0; i < n; i++){
            ll a; cin >> a;
            ll cnt2 = 0;
            while(a % 2 == 0){
                cnt2++;
                a /= 2;
            }

            // Logic Correction:
            // We absorb if Current Full Value (a * 2^cnt2) > Stack Base (q)
            while (st.size()) {
                const auto &[q, p] = st.top();
                
                //if cnt2 >= 30, a * 2^30 > 10^9 >= q always absorb
                // if calculated value > q
                // s1=q*2^p + a*2^cnt2
                // s2=q+a*2^(cnt2+p)
                // whichever of q or 2^cnt2 is larger, utilizes 2^p better
                if (cnt2 >= 30 || (a * (1ll << cnt2)) > q) {
                    // remove stack top's contribution
                    sum = (sum - (q % MOD) * modexp(2, p) % MOD + MOD) % MOD;
                    // add back the q
                    sum = (sum + q) % MOD;
                    cnt2 += p; // steal the powers of 2
                    st.pop();
                } else {
                    break;
                }
            }
            
            // add current no's contri
            sum %= MOD;
            sum = (sum + (a % MOD) * modexp(2, cnt2)) % MOD;
            cout << sum << ' ';
            st.emplace(a, cnt2);
       }
       cout << '\n';
    }
    return 0;
}