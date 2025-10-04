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
       int n;cin>>n;
       vector<ll> k(n),h(n);for(auto &i:k) cin>>i;
       for(auto &i:h) cin>>i;
       vector<pair<int,int>> itvls;
       for(int i=0;i<n;i++){
        itvls.emplace_back(k[i]-h[i]+1,k[i]);
       }
       sort(all(itvls));
       
       // unite the intervals and find the ans
       ll ans=0ll;
       auto [l,r]=itvls[0];
       for(int i=1;i<n;i++){
        auto [cur_l,cur_r]=itvls[i];
        // check for intersection
        if(cur_l<=r){
            r=max(r,cur_r); // extend to the right
        }
        // no intersection, simply compute the ans for this segment and add up
        else{
            ll len=(r-l+1);
            ans+=len*(len+1)/2;
            // start from a new segment now
            l = cur_l;
            r = cur_r;
        }
       }
       // add for last segment
       ll len=(r-l+1);
       ans+=len*(len+1)/2;

       cout<<ans<<"\n";

    }
    return 0;
}