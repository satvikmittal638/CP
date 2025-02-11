#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
const int MAX=2*1e5;
vector<bool> is_prime(MAX + 1, true);

for (int p = 2; p * p <= MAX; p++) {
      if (is_prime[p] == true) {
          for (int i = p * p; i <= MAX; i += p)
              is_prime[i] = false;
      }
  }

  vector<int> primes;
  for(int p = 2; p <= MAX; p++)
      if (is_prime[p])primes.emplace_back(p);
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> cnt(n+1,0);
       set<int> a;
       ll P=0ll,ans=0ll;
       for(int i=0;i<n;i++) {
        int x;cin>>x;
        P+=is_prime[x];
        a.insert(x);
        cnt[x]++;
       }
       for(auto x:a){
        if(is_prime[x]) {
            ans+=cnt[x]*(P-cnt[x])/2;
        }
        else{
            for(auto p:primes){
                // its a semiprime
                if(x%p==0 && is_prime[x/p]){
                    ans+=cnt[x]*(cnt[p]+(p*p!=x)*cnt[x/p]);
                    ans+=cnt[x]*(cnt[x]+1)/2;
                    break;
                }
            }
        }
       }
       cout<<ans<<"\n";
    }
    return 0;
}