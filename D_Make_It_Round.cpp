#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
int main()
{
    fastio;
    int tt;
    cin >> tt;
    while (tt--)
    {
        ll n, m;
        cin >> n >> m;
        ll pow2 = 0ll, pow5 = 0ll;
        ll tmp = n;
        while (tmp % 2 == 0)
        {
            tmp /= 2;
            pow2++;
        }
        tmp = n;
        while (tmp % 5 == 0)
        {
            tmp /= 5;
            pow5++;
        }
        ll k = 1;
        if (pow2 < pow5)
        {
            k = (1ll << min((ll)log2(m), pow5 - pow2));
        }
        else if (pow2 > pow5)
        {
            ll log5 = (ll)(log(m) / log(5)); 
            k = pow(5, min(log5, pow2 - pow5)); 
        }
        // try adding power of 10 now
        while(k*10<=m){
            k*=10;
        }
        // now try maximizing the number by using higher multiples of k
        ll tmpk=k;
        for(;k+tmpk<=m;k+=tmpk);
        n*=k;
        cout<<n<<"\n";
    }
return 0;
}