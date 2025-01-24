#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    ll n,S;cin>>n>>S;
    vector<ll> a(n);for(auto &i:a) cin>>i;
    auto getCost=[&](ll k){
        vector<ll> b(n);
        for(ll i=0;i<n;i++){
            b[i]=a[i]+(i+1)*k;
        }
        sort(all(b));
        ll minCost=accumulate(b.begin(),b.begin()+k,0ll);
        return minCost;
    };
    // BS for k
    ll lo=0,hi=n;
    ll kans,costans;
    while(lo<=hi){
        ll mid=(lo+hi)/2;
        ll cost=getCost(mid);
        if(cost<=S){
            kans=mid;
            costans=cost;
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    cout<<kans<<" "<<costans;
    return 0;
}