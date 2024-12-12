#include<iostream>
#include<math.h>
using namespace std;

int isPrime(int k){
    for(int i=2;i<=sqrt(k);i++){
        if(k%i==0){
            return 0;
        }
    }
    return 1;
}

int nxtPrime(int n){
    if(n==2){
        return 3;
    }
    // odd primes
    for(int i=n;;i+=2){
        if(isPrime(i) && i!=n){
            return i;
        }
    }
    return -1;// never executed
}

int main()
{
    int n,m;
    cin>>n>>m;
    // cout<<nxtPrime(n);
    if(m==nxtPrime(n)){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}