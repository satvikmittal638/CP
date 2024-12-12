#include<bits/stdc++.h>
using namespace std;

void print(vector<int> v){
    for(auto e:v) cout<<e<<" ";cout<<"\n";
}
int main()
{
    //cross out all primes and nums with #2 prime factors
    const int MAXN=1000;
    vector<bool> is_prime(MAXN+1,true),is_lucky(MAXN+1,true);
    is_prime[0]=is_prime[1]=is_lucky[0]=is_lucky[1]=false;
    vector<int> primes,luckies;
    //compute primes
    for(int i=2;i*i<=MAXN;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=MAXN;j+=i) is_prime[j]=false;
        }
    }
    for(int i=2;i<=MAXN;i++) {if(is_prime[i]) primes.emplace_back(i);}
    

    // remove all numbers with 1 or 2 prime factors only
    for(int i=2;i<=MAXN;i++){
        set<int> primeFactors;
        for(int j=0;j<primes.size() && primes[j]<=i;j++){
            if(i%primes[j]==0) primeFactors.insert(primes[j]);
        }
        if(primeFactors.size()<=2) {
            // cout<<i<<" not lucky "<<primeFactors.size()<<"\n";
            is_lucky[i]=false;
        }
    }

    // make lucky numbers list
    for(int i=2;i<=MAXN;i++) {if(is_lucky[i]) luckies.emplace_back(i);}
    
    
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
        cout<<luckies[n-1]<<"\n";
    }
    return 0;
}