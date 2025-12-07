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
       vector<ll> r(n);
       multiset<ll> q;
       for(int i=0;i<n;i++){
        ll x;cin>>x;
        q.insert(x);
       }
       for(auto &i:r) cin>>i;
       sort(all(r));

       // choose smaller remainder's first
       ll ans=0ll;
       for(int i=0;i<n;i++){
        ll up=(k-r[i])/(r[i]+1); 
        // cout<<up<<"  ";
        // for(auto e:q) cout<<e<<' ';
        // cout<<'\n';
        auto it=q.upper_bound(up);
        if(it!=q.end() && (*it)*(r[i]+1)<=(k-r[i])){
            q.erase(it);
            ans++;
        }
        else if(it!=q.begin()){
            it--;
            q.erase(it);
            ans++;
        }
       }
       cout<<ans<<'\n';
    }
    return 0;
}