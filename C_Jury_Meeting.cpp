#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

long long fastmmi(long long a, long long mod) {
    long long res = 1, exp = mod - 2;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        exp /= 2;
    }
    return res;
}

int main()
{
fastio;
    const ll MOD=998244353;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n);
       for(auto &i:a) cin>>i;
       int mx1=*max_element(all(a));
       int f1=count(all(a),mx1),f2=count(all(a),mx1-1);
       ll ans=1ll;
       for(int i=2;i<=n;i++){
        ans*=i;
        ans%=MOD;
       }
       if(f1>1){
        cout<<ans<<"\n";
        continue;
       }
       ans*=f2;
       ans%=MOD;
       ans*=fastmmi(f2+1,MOD);
       ans%=MOD;
       cout<<ans<<"\n";
    }
    return 0;
}