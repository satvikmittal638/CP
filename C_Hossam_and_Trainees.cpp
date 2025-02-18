#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
const int MAX=1e5;
vector<bool> is_prime(MAX+1, true);
is_prime[0] = is_prime[1] = false;  // 0 and 1 are not prime

for (int i = 2; i * i <= MAX; ++i) {
    if (is_prime[i]) {
        for (int j = i * i; j <= MAX; j += i) {
            is_prime[j] = false;  // Mark multiples of i as non-prime
        }
    }
}
vector<int> primes;
// Printing all prime numbers
for (int i = 2; i <= MAX; ++i) {
    if (is_prime[i]) primes.push_back(i);
}
    int tt;cin>>tt;
    while(tt--){
        int n;cin>>n;
        vector<int> a(n);for(auto &i:a) cin>>i;
        bool ok=0;
        for(auto p:primes){
            int cnt=0;
            for(int i=0;i<n;i++){
                cnt+=(a[i]%p==0);
            }
            if(cnt>=2){
                ok=1;break;
            } 
        }
        cout<<(ok?"YES":"NO")<<"\n";
    }
    return 0;
}