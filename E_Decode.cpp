#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll MOD=1e9+7;
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       string s;cin>>s;
       ll n=s.length();
       // dif[n+i] stores the sum of l+1 with target sum of i
       vector<ll> dif(2*n+1,0ll);
       int cur=0;
       dif[cur+n]+=1; // empty prefix
       ll ans=0ll;
       for(ll i=0;i<n;i++){
        cur+=(s[i]=='1')-(s[i]=='0');
        ans+=(n-i)*dif[cur+n];
        ans%=MOD;
        dif[cur+n]+=i+2ll;
       }
       cout<<ans<<"\n";
    }
    return 0;
}