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
       vector<ll> a(n),pref(n);
       int pos=n;
       for(int i=0;i<n;i++) {
        cin>>a[i];
        pref[i]=a[i];
        if(i>0) pref[i]+=pref[i-1];
        if(a[i]!=1 && a[i]!=-1) pos=i;
       }
       // find minm and maxm subarray sum in [st,end](both inclusive)
       auto sumRange=[&](int st,int end){
            ll mnPref,mxPref,mnSum,mxSum;
            mnPref=mnSum=mxPref=mxSum=0ll;
            for(int r=st;r<=end;r++){
                mnSum=min(mnSum,pref[r]-mxPref);
                mxSum=max(mxSum,pref[r]-mnPref);
                mnPref=min(mnPref,pref[r]);
                mxPref=max(mxPref,pref[r]);
            }
            return make_pair(mnSum,mxSum);
       };
       // [0,pos-1]
       auto [mn1,mx1]=sumRange(0,pos-1);
       // [pos+1,n-1]
       auto [mn2,mx2]=sumRange(pos+1,n-1); 

       // find min and maxm subarray sum for all subarrays containing x
       ll mnPref,mxPref,mnSum,mxSum;
        mnPref=mnSum=mxPref=mxSum=0ll;
       // find mnPref and mxPref in [0,pos]
       for(int r=0;r<=pos;r++){
        mnPref=min(mnPref,pref[r]);
        mxPref=max(mxPref,pref[r]);
       }
       // find mnSum and mxSum for r in [pos,n-1]
       for(int r=0;r<=pos;r++){
        mnSum=min(mnSum,pref[r]-mxPref);
        mxSum=max(mxSum,pref[r]-mnPref);
       }
       cout<<mn1<<" "<<mx1<<"\n";
       cout<<mn2<<" "<<mx2<<"\n";
       cout<<mnSum<<" "<<mxSum<<"\n";
       set<ll> ans;
       auto populate=[&](ll l,ll r){
        for(int i=l;i<=r;i++) ans.insert(i);
       };
       populate(mn1,mx1);
       populate(mn2,mx2);
       populate(mnSum,mxSum);
    //    for(auto e:ans) cout<<e<<" ";
       cout<<"\n";

       
    }
    return 0;
}