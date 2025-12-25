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
       ll n,m,k,q;cin>>n>>m>>k>>q;
       vector<pair<int,int>> qs;
       while(q--){
        int x,y;cin>>x>>y;
        qs.emplace_back(x,y);
       }
       reverse(all(qs));
       set<int> xs,ys;
       ll ans=1ll;
       for(const auto &[x,y]:qs){
        bool canColor=1;
        // check if x-th row or y-th col can be colored
        if((ys.size()==m || xs.count(x)) && (xs.size()==n || ys.count(y))) canColor=0;

        if(canColor){
            ans=(ans*k)%MOD;
        }
        xs.insert(x);
        ys.insert(y);
       }
       cout<<ans<<'\n';
    }
    return 0;
}