#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

vector<int> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}


int main()
{
fastio;
    vector<int> primes=sieveOfEratosthenes(1e6);
    int tt;cin>>tt;
    while(tt--){
        string racoon_id;
        ll n,l;
        cin>>racoon_id>>n>>l;
        string ans;
        for(auto p:primes){
            ll cnt_pow=0ll;
            while(n%p==0 && n>0){
                n/=p;
                cnt_pow++;
            }
            if(ans.size()<l)
                ans.push_back(racoon_id[cnt_pow]);
            else
                break;
        }
        cout<<ans<<"\n";
    }
    return 0;
}