#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n;cin>>n;
    vector<pair<ll,ll>> item(n);
    for(auto &[b,a]:item) cin>>a>>b;
    sort(all(item)); // sort by b[i]
    int l=0,r=n-1;
    ll cntBought=0ll,ans=0ll;
    while(l<=r){
        // keep buying from r until u have a discount on l
        while(l<=r && item[l].first>cntBought){
            ll gap=item[l].first-cntBought;
            if(gap>=item[r].second){
                cntBought+=item[r].second;
                ans+=2*(item[r].second);
                item[r].second=0;
                r--;// this item exhausted
            }
            else{
                cntBought+=gap;
                ans+=2*gap;
                item[r].second-=gap;
            }
        }
        // now buy l-th item for discount
        cntBought+=item[l].second;
        ans+=item[l].second;
        l++;
    }
    cout<<ans<<"\n";
    return 0;
}