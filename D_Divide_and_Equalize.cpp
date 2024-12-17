#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX=1e6;
    //precompute min-prime factor of each number
    vector<int> min_prime(MAX+1);
    //initialize min_prime[i]=i
    iota(min_prime.begin(),min_prime.end(),0); 
    for(int i=2;i*i<=MAX;i++){
// skip non-prime number
        if(min_prime[i]!=i) continue; 
// Any multiple of i less than i * i (i.e., i * 2, i * 3, ... i * (i - 1)) has a smaller prime factor than i.
// Any number >= i * i may have i as it's minimum prime factor
    for(int j=i*i;j<=MAX;j+=i){
        min_prime[j]=min(min_prime[j],i);
    }
    }

    int tt;cin>>tt;
    // vector<int> ctr(MAX+1,0); 
    // count total power of each prime factor in the array
    while(tt--){
        int n;cin>>n;
        map<int,int> ctr;
        auto primeFactorise=[&](int k){
            while(k>1){
                int smallest_prime_factor_of_k=min_prime[k];
                ctr[smallest_prime_factor_of_k]++;
                k/=smallest_prime_factor_of_k;
            }
        };
        for(int i=0;i<n;i++){
            int a;cin>>a;
            primeFactorise(a);
        }
        bool ok=1;
        for(auto p:ctr){
            if(p.second%n!=0) {
                ok=0;break;
            }
        }
        cout<<(ok?"YES":"NO")<<"\n";
    }
    return 0;
}