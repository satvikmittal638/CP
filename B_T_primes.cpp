#include<bits/stdc++.h>
using namespace std;
int main()
{
    const int MAX=1e6;
    vector<bool> is_prime(MAX+1,1);
    is_prime[1]=0;
    for(int i=2;i*i<=MAX;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=MAX;j+=i){
                is_prime[j]=0;
            }
        }
    }
    int n;cin>>n;
    while(n--){
        long long x;cin>>x;
        long long x_sqrt=sqrt(x);
    // T primes are squares of prime numbers
        if(x_sqrt*x_sqrt==x && is_prime[x_sqrt]){
            cout<<"YES";   
        }else{
            cout<<"NO";
        }
        cout<<"\n";
    }
    return 0;
}