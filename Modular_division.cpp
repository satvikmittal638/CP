#include<bits/stdc++.h>
using namespace std;

long long fastmmi(long long a, long long mod) {
    long long res = 1, exp = mod - 2;
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
    long long a,b,n;cin>>a>>b>>n;
    cout<<((a%n)*(fastmmi(b,n)))%n;
    return 0;
}