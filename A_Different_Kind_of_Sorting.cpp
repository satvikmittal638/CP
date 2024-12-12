#include<bits/stdc++.h>
using namespace std;
#define M 2000000
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

int getPrimeFactorCount(int n) {
  static vector<int> min_prime=minPrime(M); // avoids recalculation of minPrime list :)
  int count=0;
  while (n > 1) {
    int smallest_prime_factor_of_n = min_prime[n];
    count++;
    n /= smallest_prime_factor_of_n;
  }
  return count;
}

bool comp(pair<int,int> p1,pair<int,int> p2){
    if(p1.second!=p2.second) return p1.second<p2.second;
    return p1.first<p2.first;
}

int main()
{
    // pre-processing
    // Sort numbers in range [1,2*1e6] acc to given criteria 
    // Build an array of pairs(number,count of factors) 
    vector<pair<int,int> > nums(M+1); 
    for(int i=1;i<=M;i++){
        nums[i]=make_pair(i,getPrimeFactorCount(i));
    }
    sort(nums.begin()+1,nums.end(),comp);// to handle case for 0

    int n,i=1;
    while (true) {
        cin >> n;
        if (n == 0) break;
        cout << "Case " << i++ << ": " << nums[n].first << "\n";
        
    }
    return 0;
}