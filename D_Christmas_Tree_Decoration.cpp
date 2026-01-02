#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int MOD = 998244353;
const int MAXN = 100;

ll fact[MAXN], invFact[MAXN];

// Modular Exponentiation
ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Modular Inverse
ll modInverse(ll n) {
    return power(n, MOD - 2);
}

// Precompute factorials
void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = modInverse(fact[i]);
    }
}

// nCr function
ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    ll S = 0;
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
        S += a[i];
    }

    ll k = S / n;
    int rem = S % n;

    ll base = 0;
    int cheaps = 0;     // can take extra load for free
    int exps = 0; // cost 1 extra from box 0 to take extra load

    for (int i = 1; i <= n; i++) {
        ll low_cost = max(0ll, k - a[i]);
        base += low_cost;

        if (a[i] > k) {
            cheaps++;
        } else {
            exps++;
        }
    }

    ll lt = a[0] - base;
    
    if (lt < 0) {
        cout << 0 << '\n';
        return;
    }

    ll ans = 0;

    // now try choosing expensive ppl to put in high demand grps->cost increases by 1
    for (int c = 0; c <= exps; c++) {
        // need (rem - c) people from the cheap group to fill high demand grp
        int need_cheap = rem - c;
        
        if (need_cheap < 0) continue; // picked too many expensive, exceeded slots
        if (need_cheap > cheaps) continue; // not enough cheap people
        if (c > lt) break; // costs too much for box 0

        ll ways = (nCr(exps, c) * nCr(cheaps, need_cheap)) % MOD;
        
        ans = (ans + ways) % MOD;
    }

    // first rem ppl of the permutation put k+1 decors
    // high group positions can be swapped, low group positions can be swapped
    ans = (ans * fact[rem]) % MOD;
    ans = (ans * fact[n - rem]) % MOD;

    cout << ans << '\n';
}

int main() {
    fastio;
    precompute();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}