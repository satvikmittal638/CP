#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll MOD=998244353;
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       ll x;cin>>x;
       ll mx=x,mn=x;
       ll waysMn,waysMx;
       if(x>=0) waysMn=waysMx=2ll;// op-1/op-2 doesn't matter
       else waysMn=waysMx=1ll; // op-1 for min, op-2 for max
       for(int i=1;i<n;i++){
        cin>>x;
        vector<ll> op={mx+x,abs(mx+x),mn+x,abs(mn+x)};
        ll curWaysMx=0ll, curWaysMn=0ll;
        for(auto e:op){
            if(e>=mx){
                mx=e;
                curWaysMx++;
            }
            if(e<=mn){
                mn=e;
                curWaysMn++;
            }
        }
        if(curWaysMx>0)waysMx*=curWaysMx;
        waysMx%=MOD;
        if(curWaysMn)waysMn*=curWaysMn;
        waysMn%=MOD;
       }
       cout<<waysMx<<"\n";
    }
    return 0;
}