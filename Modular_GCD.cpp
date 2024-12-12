#include<bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;

long long modexp(long long base, long long exp, long long mod) {
    long long res = 1;
    base%=mod; // reduce the base
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
    int tt;cin>>tt;
    while(tt--){
       long long a,b,n;cin>>a>>b>>n;
       // gcd(0,a^n+b^n)=a^n+b^n
       if(a==b) {cout<<(2*modexp(a,n,MOD))%MOD<<"\n";continue;}
       
       long long hcf=1;
        for(long long i=1;i*i<=(a-b);i++){
            if((a-b)%i==0){
                long long f1=i,f2=(a-b)/i; // f2>=f1 for sure

                if((modexp(a,n,f2)+modexp(b,n,f2))%f2==0){
                    hcf=f2;break; // found the largest factor of (a-b) dividing a^n+b^n
                }
                else if((modexp(a,n,f1)+modexp(b,n,f1))%f1==0){
                    hcf=f1;// can increase the hcf since f1 is increasing
                }
            }
        }
        hcf%=MOD;
        cout<<hcf<<"\n";
    }
    return 0;
}