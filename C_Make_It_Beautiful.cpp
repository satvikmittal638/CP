#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       ll n,k;cin>>n>>k;
       vector<ll> a(n);
       ll ans=0ll;
       for(auto &i:a) {
        cin>>i;
        ans+=__builtin_popcountll(i);
       }
       for(int pos=0;pos<63;pos++){
        for(auto &e:a){
            ll mask=(1ll<<pos);
            // set the bit
            if((e&mask)==0 && k>=mask){
                e+=mask;
                ans++;
                k-=mask;
            }
        }
       }
       cout<<ans<<"\n";
    }
    return 0;
}