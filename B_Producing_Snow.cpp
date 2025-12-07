#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
struct VeniceSet{
    multiset<ll> S;
    ll water_lvl=0ll;
    void add(ll v){
        S.insert(v+water_lvl);
    }
    void remove(ll v){
        S.erase(S.find(v+water_lvl));
    }
    // decreases all elts by v
    void updateAll(ll v){
        water_lvl+=v;
    }
    ll getMin(){
        return *S.begin()-water_lvl;
    }
    ll size(){
        return S.size();
    }
};
int main()
{
fastio;
    ll n;cin>>n;
    vector<ll> v(n);for(auto &i:v) cin>>i;
    VeniceSet vs;
    for(ll i=0;i<n;i++){
        ll t;cin>>t;
        vs.add(v[i]);
        vs.updateAll(t);//decrease all by t
        ll total=t*vs.size();
        // remove additional contributions from those piles which were already <t
        ll low;
        while(vs.size() && (low=vs.getMin())<0){
            total-=abs(low);
            vs.remove(low);
        }
        cout<<total<<' ';
    }
    return 0;
}