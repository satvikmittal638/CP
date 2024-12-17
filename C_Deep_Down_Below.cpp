#include<bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(),x.end()
using namespace std;
int main()
{
    fastio;
    int tt;cin>>tt;
    while(tt--){
       ll n;cin>>n;
       vector<vector<ll>> a(n,vector<ll>());
        for(int i=0;i<n;i++){
            ll k;cin>>k;
            for(int j=0;j<k;j++){
                ll x;cin>>x;
                a[i].emplace_back(x);
            }
        }

        auto getB=[](vector<ll>& v){
            ll b=0ll;
            for(int i=0;i<v.size();i++){
                b=max(b,v[i]-i);
            }
            return b;
        };
        sort(all(a),[&](auto v1,auto v2){
            return getB(v1)<getB(v2);
        });
        ll p=0ll,sum=0ll;
        for(int i=0;i<n;i++){
            p=max(p,getB(a[i])-sum);
            sum+=a[i].size();
        }
        p++;
        cout<<p<<"\n";
    }
    return 0;
}