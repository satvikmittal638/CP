#include<bits/stdc++.h>
using namespace std;


long long modexp(long long base, long long exp, long long mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main()
{
    const int MOD=1e9+7;
    int n;cin>>n;
    while(n--){
        int a,b,c;cin>>a>>b>>c;
        int pow=modexp(b,c,MOD-1);
        int ans=modexp(a,pow,MOD);
        cout<<ans<<"\n";
    }
    return 0;
}