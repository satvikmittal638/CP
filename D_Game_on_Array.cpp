#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    ll tt;cin>>tt;
    while(tt--){
       ll n;cin>>n;
       vector<ll> a(n);
       map<ll,ll> cnt;
       for(auto &i:a) {cin>>i;cnt[i]++;}
       ll A=0ll,B=0ll;
       // evens with high freq are preferred(so that chance again throws back to alice)
       vector<pair<ll,ll>> inv_cnt;// value,cnt
       for(auto &[k,v]:cnt){
        if(k%2==0){
            A+=(k/2)*v;
            B+=(k/2)*v;
        }else{
            inv_cnt.push_back({v,k});
        }
       }
       sort(rall(inv_cnt));
       for(ll i=0;i<inv_cnt.size();i+=2){
        auto [c,v]=inv_cnt[i];
        A+=((v+1)/2)*c;
        B+=((v-1)/2)*c;
       }
       // Now chance throws back to B
       for(ll i=1;i<inv_cnt.size();i+=2){
        auto [c,v]=inv_cnt[i];
        B+=((v+1)/2)*c;
        A+=((v-1)/2)*c;
       }
       cout<<A<<" "<<B<<"\n";

    }
    return 0;
}