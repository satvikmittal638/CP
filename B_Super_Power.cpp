#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

ll modexp(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

// To reduce a large number represented as a string modulo m
ll reduceLargeExponent(const string& largeExp, ll mod) {
    ll reduced = 0;
    for (char digit : largeExp) {
        reduced = (reduced * 10 + (digit - '0')) % mod;
    }
    return reduced;
}

int main() {
    ll n;
    string E;
    cin >> n >> E;

    const ll MOD = 1429162625;
    const ll PHI = 3276000; 
    ll expMod = reduceLargeExponent(E, PHI);

    ll result = modexp(n, expMod, MOD);

    cout << result;
    return 0;
}