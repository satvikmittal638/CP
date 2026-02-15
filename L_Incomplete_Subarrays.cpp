#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
struct SegTree{
    ll size;
    vector<ll> maxs;
 
    void build(vector<ll>& a,ll x,ll lx,ll rx){
        if(rx-lx==1){
            if(lx<(ll)a.size()){
                maxs[x]=a[lx];
            }
            return;
        }
        ll m=(lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        maxs[x]=max(maxs[2*x+1],maxs[2*x+2]);
    }
 
    SegTree(vector<ll>& a){
        ll n=a.size();
        size=1;
        while(size<n)size*=2;
        maxs.assign(2*size,LLONG_MIN);
        build(a,0,0,size);
    }
 
    void set(ll i,ll val,ll x,ll lx,ll rx){
        if(rx-lx==1){
            maxs[x]=val;
            return;
        }
        ll m=(lx+rx)/2;
        if(i<m){
            set(i,val,2*x+1,lx,m);
        }else{
            set(i,val,2*x+2,m,rx);
        }
        maxs[x]=max(maxs[2*x+1],maxs[2*x+2]);
    }
 
    void set(ll i,ll val){
        set(i,val,0,0,size);
    }
   
    ll getmax(ll l,ll r,ll x,ll lx,ll rx){
        if(lx>=r || rx<=l){
            return LLONG_MIN;
        }
        if(l<=lx && rx<=r){
            return maxs[x];
        }
        ll m=(lx+rx)/2;
        return max(getmax(l,r,2*x+1,lx,m),getmax(l,r,2*x+2,m,rx));
    }
    ll getmax(ll l,ll r){
        return getmax(l,r,0,0,size);
    }
 
};

int main()
{
fastio;
    ll tt;cin>>tt;
    while(tt--){
       ll n,k;cin>>n>>k;
        vector<ll> a(n+1);
        for(ll i=1;i<=n;i++) cin>>a[i];
        // checks if a given x works
        auto isSafe=[&](ll x){
            // cnt[i] is no. of elts>=x in [1,i]
            vector<ll> cnt(n+1,0),s(n+1,0);
            for(ll i=1;i<=n;i++){
                cnt[i]=cnt[i-1]+(a[i]>=x);
                s[i]=s[i-1]+max(0ll,x-a[i]);
            }
            for(ll i=0;i<=n;i++){
                cnt[i]=2*cnt[i]-i;
            }
            SegTree sgt(cnt);
            for(ll l=0;l<n;l++){
                // consider a[l+1,r]
                // fix an l, find maxm r s.t. s[r]-s[l]<=k
                // s[r] <= s[l]+k -> sum of [l+1,r]
                auto it=upper_bound(all(s),s[l]+k);
                it--;
                ll r=it-s.begin();
                // then use segment tree to get maxm of cnt[i] on [l,r]
                // it must include atleast 2 ets -> r>l+1
                ll mx=sgt.getmax(l+2,r+1); // [l+1,r]
                // check if this is >cnt[l]
                if(mx>cnt[l]) return 1;
            }
            return 0;
        };

        ll lo=0,hi=1e9,ans=-1;
        while(lo<=hi){
            ll mid=(lo+hi)/2;
            if(isSafe(mid)){
                ans=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        cout<<ans<<'\n';

    }
    return 0;
}