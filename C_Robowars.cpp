#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    const ll MAX=1e5+5;
    // preprocessing
    vector<bool> is_prime(MAX, 1);
    is_prime[0] = is_prime[1] = 0; // 0 and 1 are not prime
    for (ll i = 2; i < MAX; i++) {
        if (is_prime[i]) {
            for (ll j = 1LL * i * i; j < MAX; j += i) {
                is_prime[j] = 0; 
            }
        }
    }
    vector<ll> cnt(MAX,0);
    // count number of primes from [1,i]
    for(ll i=2;i<MAX;i++){
        cnt[i]=cnt[i-1]+is_prime[i];
    }
    ll tt;cin>>tt;
    while(tt--){
       ll r1,r2,N;cin>>r1>>r2>>N;
       string s;cin>>s;
       s=' '+s;
       if(s[1]=='*'){
        cout<<"No way!\n";
        continue;
       }
       vector<ll> dp(MAX,MAX);
       dp[1]=0;
       for(ll i=1;i<=N;i++){
        if(s[i]=='#'){
            ll A=cnt[i];
            if(r2*A>=r1*i && i+A<=N && s[i+A]=='#'){
                dp[i+A]=min(dp[i+A],1+dp[i]);
            }
            if(i+2<=N && s[i+2]=='#') dp[i+2]=min(dp[i+2],1+dp[i]);
            if(i+1<=N && s[i+1]=='#') dp[i+1]=min(dp[i+1],1+dp[i]);
        }
       }
       
       if(dp[N]>=MAX){
        cout<<"No way!";
       }
       else{
        cout<<dp[N];
       }
       cout<<"\n";
    }
    return 0;
}