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
       vector<ll> a(n);for(auto &i:a) cin>>i;
       set<ll> prvs;
       ll mxGain=0ll,curS=0ll;// maximize the gain
       prvs.insert(0ll);
       for(ll i=0;i<n;i++){
        curS+=a[i];
        ll mxPrev=*prvs.rbegin();
        mxGain=max(mxGain,(i+1)*(i+2)-curS+mxPrev);
        prvs.insert((i+2)-(i+2)*(i+2)+curS);
       }
       cout<<accumulate(all(a),0ll)+mxGain<<'\n';

    }
    return 0;
}