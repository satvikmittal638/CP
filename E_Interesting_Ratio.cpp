#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    // preprocessing
    const int N = 1e7 + 1; 
    vector<bool> is_prime(N, 1);
    is_prime[0] = is_prime[1] = 0; // 0 and 1 are not prime
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) {
            for (ll j = 1LL * i * i; j < N; j += i) {
                is_prime[j] = 0; 
            }
        }
    }
    vector<int> cnt(N,0);
    // count number of primes from [1,i]
    for(int i=2;i<N;i++){
        cnt[i]=cnt[i-1]+is_prime[i];
    }

    int tt;cin>>tt;
    while(tt--){
        int n;cin>>n;
        int ans=0;
        for(int a=1;a<n;a++){
            ans+=cnt[n/a];
        }
        cout<<ans<<"\n";
    }
    return 0;
}