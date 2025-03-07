#include<iostream>
using namespace std;
#define MOD 998244353
long long fast_pow(long long base, long long n,long long M)
{
    if(n==0)
       return 1;
    if(n==1)
    return base;
    long long halfn=fast_pow(base,n/2,M);
    if(n%2==0)
        return ( halfn * halfn ) % M;
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}

int main()
{
    int w,h;
    cin>>w>>h;
    cout<<fast_pow(2,w+h,MOD);
    return 0;
}