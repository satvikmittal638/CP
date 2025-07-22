#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll mod=1e9+7;

ll powmod(ll a, ll exp) {
    ll res = 1ll;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        exp /= 2;
    }
    return res;
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       ll n,k;cin>>n>>k;
       if(n%2==0){
        /*
    for a position i, keep the prefix [k-1,i+1] equal to 0s in both AND as well as XOR
    set position AND=1 and XOR=0 at position i
    now the suffix [i-1,0] can be anything
    
    multiply both the ways of making the prefix and the suffix
    and add all such ways for each i
        
        */
           ll ans = 0, mul = 1;
           for (int i = k - 1; i >= 0; i--) {
               ll add = (mul * powmod(powmod(2, n), k - 1 - i)) % mod;
               ans = (ans + add) % mod;
               mul = (mul * ((powmod(2, n - 1) - 1 + mod) % mod)) % mod;
           }
           ans = (ans + mul) % mod; // for case when the suffix has length 0(i.e. all bits are kept at 0)
           cout << ans << "\n";
        }
       else{
        /*
        Can use all 1s -> 1 way --> and=xor=1
        Can use even 1s<n -> 2^(n-1) ways --> and=xor=0
         using any of the 2 ways results in and=xor, so all bits are constrained
        */
        ll ans=powmod((powmod(2,n-1)+1ll)%mod,k);
        cout<<ans<<"\n";
       }
    }
    return 0;
}