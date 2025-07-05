#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

/* Iterative Function to calculate (x^y)%p
in O(log y) */
unsigned long long power(unsigned long long x, int y, int p)
{
    unsigned long long res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    while (y > 0) {

        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, int p)
{
    return power(n, p - 2, p);
}
unsigned long long mul(unsigned long long x,
                       unsigned long long y, int p)
{
    return x * 1ull * y % p;
}
unsigned long long divide(unsigned long long x,
                          unsigned long long y, int p)
{
    return mul(x, modInverse(y, p), p);
}
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
    // if n-r is less calculate nCn-r
    if (n - r < r)
        return nCrModPFermat(n, n - r, p);

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long res = 1;
    // keep multiplying numerator terms and dividing denominator terms in res
    for (int i = r; i >= 1; i--)
        res = divide(mul(res, n - i + 1, p), i, p);
    return res;
}

int main()
{
fastio;
    ll MOD=998244353;
    int n;cin>>n;
    vector<ll> w(n);for(auto &i:w) cin>>i;
    ll ans=1ll;
    for(int i=0;i<n-2;i+=3){
        vector<ll> tr;
        tr.push_back(w[i]);
        tr.push_back(w[i+1]);
        tr.push_back(w[i+2]);
        sort(all(tr));
        if(tr[0]==tr[1] && tr[1]==tr[2]) ans*=3ll; // all 3 same
        else if(tr[0]==tr[1] && tr[1]!=tr[2]) ans*=2ll; // bottom 2 are same
        ans%=MOD;
    }
    // ways to choose half of triangles to paint as (B,B,R) and other half as (R,R,B)
    ans*=nCrModPFermat(n/3,n/6,MOD);
    ans%=MOD;
    cout<<ans;
    return 0;
}