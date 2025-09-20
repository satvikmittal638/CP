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
       ll n;cin>>n;
       // x[i] is idx of nearest elt>a[i] to its left
       // y[i] is idx of nearest elt>a[i] to its right
       vector<ll> a(n+1,0ll),x(n+1,0),y(n+1,n+1);
       for(ll i=1;i<=n;i++) cin>>a[i];
       stack<ll> st;// mallain M.I.(from bottom to top) stack
       // nearest elt to the left
       st.push(1);
       for(ll i=2;i<=n;i++){
        while(!st.empty() && a[st.top()]<=a[i]) st.pop();
        if(!st.empty()) x[i]=st.top();
        st.push(i);
       }
       
       // clear the stack for reuse
       while(st.size()) st.pop();

       // nearest elt to the right
       st.push(n);
       for(ll i=n-1;i>=1;i--){
        while(!st.empty() && a[st.top()]<=a[i]) st.pop();
        if(!st.empty()) y[i]=st.top();
        st.push(i);
       }
    //    for(auto e:x) cout<<e<<" ";
    //    cout<<"\n";
    //    for(auto e:y) cout<<e<<" ";
    //    cout<<"\n\n";
       
    vector<ll> p(n+1,0ll),negP(n+1,0ll);

        partial_sum(all(a),p.begin());
        for(ll i=0;i<=n;i++) negP[i]=-p[i];
       SegTree sgtMax(p), sgtMaxNeg(negP);
       bool ok=1;
       for(ll i=1;i<=n;i++){
        // check the subarrays starting at a[i]
        ll mxPrefSum=sgtMax.getmax(i,y[i])-p[i-1];
        ok&=a[i]>=mxPrefSum;
        // check the subarrays ending at a[i]
        ll mxSufSum=p[i]+sgtMaxNeg.getmax(x[i],i);
        ok&=a[i]>=mxSufSum;
       }
       cout<<(ok?"YES":"NO")<<"\n";

    }
    return 0;
}