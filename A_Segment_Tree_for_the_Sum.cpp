#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

/*
i->idx of elt of the array to be set
x->idx of current node of the segtree(0 is root)
lx,rx->lower and upper bounds of the current segment being processed
*/
struct SegTree{
    int size;
    vector<ll> sums;
    SegTree(int n){
        size=1;
        // make size nearest power of 2 >=n
        // get 4n size of segtree in worst case
        while(size<n) size*=2;
        sums.assign(2*size,0ll);
    }


    void build(vector<int>& a,int x,int lx,int rx){
        if(rx-lx==1){
            //check if the current elt actually belongs to the array(we padded some empty elts)
            if(lx<a.size()){
                sums[x]=a[lx];
            }
            return;
        }
        int m=(lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        sums[x]=sums[2*x+1]+sums[2*x+2];
    }

    void build(vector<int>& a){
      build(a,0,0,size);  
    }

    void set(int i,int val,int x,int lx,int rx){
        // leaf node
        if(rx-lx==1){
            sums[x]=val;
            return;
        }
        int m=(lx+rx)/2;
        // i lies in left subtree
        if(i<m){
            set(i,val,2*x+1,lx,m);
        }
        // i lies in right subtree
        else{
            set(i,val,2*x+2,m,rx);
        }
        // update parent from leaf nodes
        // 2x+1-> left child,2x+2->right child
        sums[x]=sums[2*x+1]+sums[2*x+2];
    }

    void set(int i,int val){
        set(i,val,0,0,size);
    }

    ll sum(int l,int r,int x,int lx,int rx){
    //Case-1:current segment doesn't intersect with required segment
        if(lx>=r || l>=rx)return 0ll;
    //Case-2:current segment is contained inside the required segment
        if(lx>=l && rx<=r) return sums[x];
        int m=(lx+rx)/2;
        ll s1=sum(l,r,2*x+1,lx,m); // get required sum from left subtree
        ll s2=sum(l,r,2*x+2,m,rx);// get required sum from right subtree
        return s1+s2;
    }

    ll sum(int l,int r){
        return sum(l,r,0,0,size);
    }
};


int main()
{
fastio;
    int n,m;cin>>n>>m;
    vector<int> a(n);for(auto &i:a) cin>>i;
    SegTree st(n);
    st.build(a); // works in O(n)
    while(m--){
        int op;cin>>op;
        if(op==1){
            int i,v;cin>>i>>v;
            st.set(i,v);
        }
        else{
            int l,r;cin>>l>>r;
            cout<<st.sum(l,r)<<"\n";
        }
    }
    return 0;
}