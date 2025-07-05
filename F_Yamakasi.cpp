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
       ll n,s,x;cin>>n>>s>>x;
       vector<vector<ll>> segs;
       vector<ll> seg;
       // find continuos segments of elts <=x
       for(int i=0;i<n;i++){
        ll a;cin>>a;
        if(a<=x) {
            seg.push_back(a);
        }
        else if(seg.size()) {
            segs.push_back(seg);
            seg.clear();
        }
       }
       if(seg.size()) segs.push_back(seg); // add last segment
       
    //    for(auto &seg:segs){
    //     for(auto e:seg) cout<<e<<" ";
    //     cout<<" ";
    //    }
       // counts no. of subarrays with maxm elt=x and sum=s
       auto cntSubarrs=[&](vector<ll> seg){
        ll cntAns=0ll,pref=0ll,curCntX=0ll;
        map<ll,ll> cnt_beforex, cnt_onAfterx;
        cnt_beforex[0]=1;// empty prefix
        for(auto e:seg){
            pref+=e;
            if(e==x){
                curCntX++;
                // transfer all counts from last encountered x till before this x
                for(auto &[sum,cnt]:cnt_onAfterx){
                    cnt_beforex[sum]+=cnt;
                }
                cnt_onAfterx.clear();
            }
            if(curCntX>0) 
            {
                cntAns+=cnt_beforex[pref-s];
                // cout<<cnt_beforex[pref-s]<<" "<<pref<<"  ";
                cnt_onAfterx[pref]++;
            }
            else{
                cnt_beforex[pref]++;
            }
        }
        return cntAns;
       };

       ll ans=0ll;
       for(auto &seg:segs){
        ans+=cntSubarrs(seg);
       }
       cout<<ans<<"\n";
    }
    return 0;
}