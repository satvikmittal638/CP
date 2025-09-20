#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

// Source:GFG(Used as a blackbox)
ll sumOfDigitsFrom1ToNUtil(ll n, vector<ll> &a) {
    if (n < 10)
        return (n * (n + 1) / 2);

    ll d = (ll)(log10(n));
    ll p = (ll)(ceil(pow(10, d)));
    ll msd = n / p;

    return (msd * a[d] + (msd * (msd - 1) / 2) * p 
            + msd * (1 + n % p) + sumOfDigitsFrom1ToNUtil(n % p, a));
}

// Function to compute sum of digits in
// numbers from 1 to n
ll sumOfDigits(ll n) {
    ll d = max(((ll)(log10(n))), 1ll);
    vector<ll> a(d + 1);
    a[0] = 0;
    a[1] = 45;

    for (ll i = 2; i <= d; i++)
        a[i] = a[i - 1] * 10 + 45 * (ll)(ceil(pow(10, i - 1)));

    return sumOfDigitsFrom1ToNUtil(n, a);
}

int main()
{
fastio;
    ll tt;cin>>tt;
    while(tt--){
       ll k;cin>>k;
       // returns sum of length of all d digit numbers for d=1 to d=l
       auto getS=[&](ll l){
        return (l*pow(10,l+1)-(l+1)*pow(10,l)+1)/9;
       };
       // find maxm l by brute
       ll l=1;
       while((k-getS(l))>=0){
        l++;
       }
       // n is a l-digit number
    //    cout<<l<<" ";
    //    cout<<getS(l-1)<<" ";
       k-=getS(l-1); // we are done with all numbers with no. of digits(d) in [1,l-1]
    //    cout<<k<<" ";
       ll n=pow(10,l-1)+k/l; // n=10^(l-1)+roof(k/l)

       // now we compute sum of all digits of all numbers till n-1
       ll ans=sumOfDigits(n-1);
       k=k%l;
       // now we need to pick first k digits of n and add it to our ans
       string strn=to_string(n);
       for(int i=0;i<k;i++){
        ans+=strn[i]-'0';
       }
       cout<<ans<<"\n";

    }
    return 0;
}