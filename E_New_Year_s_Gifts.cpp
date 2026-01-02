#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

using pll=pair<ll,ll>; 
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       ll n,m,k;cin>>n>>m>>k;
       vector<ll> a(m);
       for(int i=0;i<m;i++){
        cin>>a[i];
       }
       sort(rall(a));

       vector<pll> req;
       for(int i=0;i<n;i++){
        ll x,y,z;cin>>x>>y>>z;
        k-=y;
        req.emplace_back(x,z-y);
       }
       if(k<0){
        cout<<"0\n";
        continue;
       }
       sort(all(req));
    //    for(auto [x,y]:req) cout<<x<<' '<<y<<'\n';
       // now we first try to buy the maxm x[i] friend with most beautiful box
       // in case of same maxm x[i], we buy the friend with maxm y-z
       vector<ll> rem;
       ll ans=0ll;
       while(a.size() && req.size()){
        ll mxBox=*a.rbegin();
        auto p=*req.rbegin();req.pop_back();
        if(mxBox>=p.first){
            ans++; // this friend is bought and so the box is used
            a.pop_back();
        }
        else{
            // this friend can't be bought, so box remains unused
            // only the cost can buy him now
            rem.emplace_back(p.second);
        }
       }
       // add back remaining elts from req to rem
       for(auto [x,y]:req) rem.emplace_back(y); // add only cost
       
       sort(rall(rem));
       // now all friends which could have been bought with a box are done
       // now buy cheapest friends with money
       while(k>0 && rem.size()){
        auto p=*rem.rbegin();rem.pop_back();
        if(p<=k){
            k-=p;
            ans++;
        }
        else{
            break;// even the cheapest can't be bought, so none can be bought
        }
       }
       cout<<ans<<'\n';



    }
    return 0;
}