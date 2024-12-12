#include<bits/stdc++.h>
using namespace std;
const int N=1e8;
void solve(){
    vector<char> is_prime(N+1,true);
    vector<int> primes;
    is_prime[0]=is_prime[1]=0;
    int cnt_prime=0;
    // to find primes from [1,N], till rootN, cross out all multiples
    for(int i=2;i*i<=N;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=N;j+=i){
                is_prime[j]=0;
            }
        }
    }
    for(int i=2;i<=N;i++) if(is_prime[i]) primes.emplace_back(i);
    for(int i=1;i<primes.size();i+=100) cout<<primes[i-1]<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}