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
       ll n;cin>>n;
       // cnt[b] denotes no. of set bits at position b acumulated over the whole array a
       vector<ll> a(n),cnt(60,0ll);
       for(auto &i:a){
        cin>>i;
        for(ll b=0ll;b<60;b++){
            ll mask=(1ll<<b);
            if(i&mask) cnt[b]++;
        }
       }
       ll ans=0ll;
       for(auto e:a){
        ll sum_and=0ll,sum_or=0ll;
        for(ll b=0ll;b<60;b++){
            ll mask=(1ll<<b);
            if(e&mask){
                mask%=MOD;
                sum_and+=(cnt[b]*mask)%MOD;
                sum_or+=(n*mask)%MOD;
            }
            else{
                mask%=MOD;
                sum_or+=(cnt[b]*mask)%MOD;
            }
            sum_and%=MOD;
            sum_or%=MOD;
        }
        ans+=(sum_and*sum_or)%MOD;
        ans%=MOD;
       }
       cout<<ans<<'\n';
    }
    return 0;
}