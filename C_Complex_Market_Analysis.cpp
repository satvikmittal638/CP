#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()


ll nC2(ll n){
    return n*(n-1)/2;
}

int main()
{
fastio;
    const int MAXN=1e6;
    vector<bool> isPrime(MAXN + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAXN; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                isPrime[j] = false;
            }
        }
    }
    int tt;cin>>tt;
    while(tt--){
       int n,e;cin>>n>>e;
       vector<int> a(n);for(auto &i:a) cin>>i;
       ll ans=0ll;
       for(int i=0;i<n;i++){
        if(isPrime[a[i]]){
            int l=i,r=i;
            ll ans1=0ll,ans2=0ll;
            while(l-e>=0 && a[l-e]==1) {
                l-=e;
                ans1++;
            }
            while(r+e<n && a[r+e]==1) {
                r+=e;
                ans2++;
            }
            ans+=ans1+ans2+ans1*ans2;

        }
       }
       cout<<ans<<"\n";
    }
    return 0;
}