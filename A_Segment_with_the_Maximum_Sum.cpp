#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

struct item{
    ll seg,pref,suf,sum;// maxm value of each
};


struct SegTree{
    int size;
    vector<item> tree;
    item NEUTRAL;
    item merge(item p1,item p2){
        ll seg=max({p1.suf+p2.pref,p1.seg,p2.seg});
        ll pref=max(p1.pref,p1.sum+p2.pref);
        ll suf=max(p2.suf,p1.suf+p2.sum);
        ll sum=p1.sum+p2.sum;
        return {seg,pref,suf,sum};
    }


    void build(vector<ll>& a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()) {
                // update leaf node
                int val=max(0ll,a[lx]);// empty segment allowed
                tree[x]={val,val,val,a[lx]}; 
            }
            return;
        }
        int m=(lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        tree[x]=merge(tree[2*x+1],tree[2*x+2]);

    }

    SegTree(vector<ll>& a){
        int n=a.size();
        size=1;
        NEUTRAL={0ll,0ll,0ll,0ll}; // empty segment is allowed so we can use 0 
        while(size<n) size*=2;
        tree.assign(2*size,NEUTRAL);
        build(a,0,0,size);
    }
    void set(int i,int val,int x,int lx,int rx){
        if(rx-lx==1){
            int ans=max(0,val);
            tree[x] = {ans,ans,ans,val}; // update the leaf node
            return;
        }
        int m=(lx+rx)/2;
        if(i<m){
            set(i,val,2*x+1,lx,m);
        }
        else{
            set(i,val,2*x+2,m,rx);
        }
        tree[x]=merge(tree[2*x+1],tree[2*x+2]);
    }

    void set(int i,int val){
        set(i,val,0,0,size);
    }

    item calc(int l,int r,int x,int lx,int rx){
        if(rx<=l || lx>=r) return NEUTRAL;
        if(l<=lx && rx<=r){
            return tree[x];
        }
        int m=(lx+rx)/2;
        return merge(calc(l,r,2*x+1,lx,m),calc(l,r,2*x+2,m,rx));
    }

    item calc(int l,int r){
        return calc(l,r,0,0,size);
    }
};



int main()
{
fastio;
    int n,m;cin>>n>>m;
    vector<ll> a(n);for(auto &i:a) cin>>i;
    SegTree sgt(a);
    cout<<sgt.calc(0,n).seg<<"\n";
    while(m--){
        ll i,v;cin>>i>>v;
        sgt.set(i,v);
        cout<<sgt.calc(0,n).seg<<"\n";
    }
    return 0;
}