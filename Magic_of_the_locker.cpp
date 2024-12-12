#include<iostream>
using namespace std;

#define MOD 1000000007
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
    int t;
    cin>>t;
    while(t--){
        long long n,ans;
        cin>>n;
        
        if(n<3){
            cout<<n<<endl;
            continue;
        }
        // observation:taking maximum powers of 3 gives maximum ans
        if(n%3==0){
            ans=fast_pow(3,n/3,MOD);
        }
        // X1 is useless, so take 1 more power of 3 out and do X4
        else if(n%3==1){
            n-=4;
            ans=(fast_pow(3,n/3,MOD) * 4)%MOD;
        }else{
            n-=2;
            ans=(fast_pow(3,n/3,MOD)*2)%MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}