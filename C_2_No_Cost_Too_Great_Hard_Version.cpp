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
min_prime.resize(MAX);
iota(begin(min_prime), end(min_prime), 0);
for (int i = 2; i * i <= MAX; i++) {
    if (min_prime[i] != i) continue;
    for (int j = i * i; j < MAX; j += i) 
        if (min_prime[j] == j) min_prime[j] = i;
}
vector<int> cnt(MAX+1,0);

int tt;cin>>tt;
while(tt--){
   int n;cin>>n;
   vector<pair<ll,int>> b_a(n); 
   for(int i=0;i<n;i++) cin>>b_a[i].second;
   for(int i=0;i<n;i++) cin>>b_a[i].first;
   sort(all(b_a)); 
   
   vector<int> a(n);
   vector<ll> b(n); 
   for(int i=0;i<n;i++){
    a[i]=b_a[i].second;
    b[i]=b_a[i].first;
   }

   bool found=0;
   set<int> used;
   // check for cost 0 
   for(auto e:a){
      for(auto p:getPrimeFactors(e)){
          if(cnt[p] > 0) {found=1;}
          cnt[p]++;
          used.insert(p);
      }
   }
   
   if(found){
       cout<<0<<'\n';
   } else {
       ll ans = b[0] + b[1]; // case 1: Increment the two cheapest elts

       // case 2: one increment on any a[i]
       for (int i = 0; i < n; i++) {
           // Check a[i] + 1
           for (auto p : getPrimeFactors(a[i] + 1)) {
               if (used.count(p)) { // Check if this prime exists elsewhere
                   ans = min(ans, b[i]);
               }
           }
       }

       // case 3: multiple increments on the cheapest element a[0]
       for (int i = 1; i < n; i++) {
           for (auto p : getPrimeFactors(a[i])) {
               ll inc_req = (ll)p - (a[0] % p);
               if (inc_req == p) inc_req = 0;
               ans = min(ans, inc_req * b[0]);
           }
       }
       cout << ans << '\n';
   }
   
   for(auto p:used) cnt[p]=0;
}
return 0;
}