#include<bits/stdc++.h>
using namespace std;

vector<int> minPrime(int MAX) {
  vector<int> min_prime(MAX + 1);
  // Set min_prime[i] = i
  iota(begin(min_prime), end(min_prime), 0);
  for (int i = 2; i * i <= MAX; i++) { 
      if (min_prime[i] != i) continue;
      // if min_prime[i] = i then i must be a prime number.
      // Any multiple of i less than i * i (i.e., i * 2, i * 3, ... i * (i - 1)) has a smaller prime factor than i.
      // Any number >= i * i may have i as it's minimum prime factor
      for (int j = i * i; j <= MAX; j += i) min_prime[j] = min(min_prime[j], i);
  }
  return min_prime;
}

int main()
{
    const int MAX=1e7;
    // Pre-processing
    // compute min prime factors of all n in (1,1e7)
    vector<int> f=minPrime(MAX);


    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long a=0;
        for(int i=2;i<=n;i++){
            a+=f[i];
        }
        cout<<a<<"\n";

    }
    return 0;
}