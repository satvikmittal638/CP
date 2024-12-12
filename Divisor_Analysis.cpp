#include<bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;

long long modexp(long long base, long long exp, long long mod) {
    long long res = 1;
    base%=mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}
long long fastmmi(long long a, long long mod) {
    return modexp(a,mod-2,mod);
}

long long cntDiv(vector<long long>& k,long long mod){
    long long cnt=1;
    for(auto pw:k){
        cnt*=(pw+1);
        if(cnt>=mod) cnt%=mod;
    }
    return cnt;
}

long long sumDiv(vector<long long>& x,vector<long long>& k){
    long long num=1,denom=1;
    for(long long i=0;i<x.size();i++){
        num*=(modexp(x[i],k[i]+1,MOD)-1);
        if(num>=MOD) num%=MOD;

        denom*=(x[i]-1);
        if(denom>=MOD) denom%=MOD;
    }
    long long sum=num*fastmmi(denom,MOD);
    if(sum>=MOD) sum%=MOD;
    return sum;
}

// TODO:some issue in this function
long long prodDiv(vector<long long>& x,vector<long long>& k){
    // a^b==a^(b%(m-1)) (mod m) if m is prime
    long long exp=cntDiv(k,MOD-1)*fastmmi(2,MOD-1);
    if(exp>=(MOD-1)) exp%=MOD-1;
    // cout<<exp<<"\n";
    long long base=1;
    for(int i=0;i<x.size();i++){
        base*=modexp(x[i],k[i],MOD);
        if(base>=MOD) base%=MOD;
    }
    long long prod=modexp(base,exp,MOD);
    return prod;
}

int main()
{
    long long n;cin>>n;
    vector<long long> x(n),k(n);
    for(long long i=0;i<n;i++){
        cin>>x[i]>>k[i];
    }
    long long numOfDiv=cntDiv(k,MOD),sumOfDiv=sumDiv(x,k),prodOfDiv=prodDiv(x,k);
    cout<<numOfDiv<<" "<<sumOfDiv<<" "<<prodOfDiv;

    return 0;
}