#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define raint(x) x.rbegin(),x.rend()
#define aint(x) x.begin(),x.end()

struct item{
    // store min and max of a[i]-i
    // ans1-> left child has min,right child has max
    // ans2-> right child has min,left child has max
    int minDiff,maxDiff,ans1,ans2;
};
 
 
struct SegTree{
    int size;
    vector<item> tree;
    item NEUTRAL;
    item merge(item p1,item p2){
        return {min(p1.minDiff,p2.minDiff),
        max(p1.maxDiff,p2.maxDiff),
        max({p1.ans1,p2.ans1,p2.maxDiff-p1.minDiff}), 
        max({p1.ans2,p2.ans2,p1.maxDiff-p2.minDiff})
        };
    }
 
    item single(int a,int i){
        return {a-i,a-i,0,0};
    }
    //<===Don't modify below this line except NEUTRAL===>
    void build(vector<int>& a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()) {
                // update leaf node
                tree[x]=single(a[lx],lx); 
            }
            return;
        }
        int m=(lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        tree[x]=merge(tree[2*x+1],tree[2*x+2]);
 
    }
 
    SegTree(vector<int>& a){
        int n=a.size();
        size=1;
        NEUTRAL={INT_MAX,INT_MIN,0,0};
        while(size<n) size*=2;
        tree.assign(2*size,NEUTRAL);
        build(a,0,0,size);
    }
    void set(int i,int val,int x,int lx,int rx){
        if(rx-lx==1){
            tree[x] = single(val,i); // update the leaf node
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
    int ans(int l,int r){
        item ans=calc(l,r);
        return max(ans.ans1,ans.ans1);
    }
};
 

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,q;cin>>n>>q;
       vector<int> a(n);for(auto &i:a) cin>>i;
        SegTree sgt(a);
        cout<<sgt.ans(0,n)<<"\n";
        while(q--){
            int p,x;cin>>p>>x;p--;
            sgt.set(p,x);
            cout<<sgt.ans(0,n)<<"\n";
        }
    }
    return 0;
}