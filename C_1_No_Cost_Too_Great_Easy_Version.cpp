#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int MAX=2*1e5+5;
vector<int> min_prime;

vector<int> getPrimeFactors(int n) {
  vector<int> prime_factors;
  while (n > 1) {
    int spf = min_prime[n];
    prime_factors.push_back(spf);
    while (n % spf == 0) n /= spf;
  }
  return prime_factors;
}

int main()
{
fastio;
// precompute(O(MAXloglogMAX))
min_prime.resize(MAX);
iota(begin(min_prime), end(min_prime), 0);
for (int i = 2; i * i <= MAX; i++) {
    if (min_prime[i] != i) continue;
    for (int j = i * i; j <= MAX; j += i)
        if (min_prime[j] == j) min_prime[j] = i;
}
vector<int> cnt(MAX+1,0);

int tt;cin>>tt;
while(tt--){
   int n;cin>>n;
   vector<int> a(n),b(n);
   for(auto &i:a) cin>>i;
   for(auto &i:b) cin>>i;
   bool found=0;
   int cntE=0;
   vector<int> used;
   // O(nlogA)
   for(auto e:a){
      if(e%2==0) cntE++;
      // O(logA)
      for(auto p:getPrimeFactors(e)){
          cnt[p]++;
          used.push_back(p);
          if(cnt[p]>=2) {found=1;break;}
      }
      if(found) break;
   }
   int ans=0;
   if(!found){
      if(cntE==1) ans=1;
      // all odds
      else{
        // now we go to each no. ,remove its contribution from cnt,increment it by 1,then again add its contribution to cnt and try to check cnt[p]>=2 while doing this
        ans = 2; 
        found = 0;

        // O(nlogA)
        for (auto e : a) {
           
            for (auto p : getPrimeFactors(e)) {
                cnt[p]--;
            }

            for (auto p : getPrimeFactors(e + 1)) {
                if (cnt[p] >= 1) { 
                    found = 1;  
                    break;
                }
            }

            for (auto p : getPrimeFactors(e)) {
                cnt[p]++;
            }

            if (found) {
                break;
            }
        }

        if (found) {
            ans = 1;
        }
      }
   }
   cout<<ans<<'\n';
   // O(nlogA)
   for(auto p:used) cnt[p]=0;
   // Total TC:O(nlogA + AloglogA)
}
return 0;
}