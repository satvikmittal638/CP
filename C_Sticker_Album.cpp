#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int INF=2*1e6+4;

/*
i->idx of elt of the array to be set
x->idx of current node of the segtree(0 is root)
lx,rx->lower and upper bounds of the current segment being processed
*/
struct SegTree{
    int size;
    vector<double> sums;
    SegTree(int n){
        size=1;
        // make size nearest power of 2 >=n
        // get 4n size of segtree in worst case
        while(size<n) size*=2;
        sums.assign(2*size,0.0);
    }
 
 
    void build(vector<double>& a,int x,int lx,int rx){
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
 
    void build(vector<double>& a){
      build(a,0,0,size);  
    }
 
    void set(int i,double val,int x,int lx,int rx){
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
 
    void set(int i,double val){
        set(i,val,0,0,size);
    }
 
    double sum(int l,int r,int x,int lx,int rx){
    //Case-1:current segment doesn't intersect with required segment
        if(lx>=r || l>=rx)return 0.0;
    //Case-2:current segment is contained inside the required segment
        if(lx>=l && rx<=r) return sums[x];
        int m=(lx+rx)/2;
        double s1=sum(l,r,2*x+1,lx,m); // get required sum from left subtree
        double s2=sum(l,r,2*x+2,m,rx);// get required sum from right subtree
        return s1+s2;
    }
 
    double sum(int l,int r){
        return sum(l,r,0,0,size);
    }
};
 

int main()
{
fastio;
    int n;
    double a,b;
    cin>>n>>a>>b;
    SegTree sgt(INF);
    vector<double> e(INF,0.0);
    sgt.build(e);
    for(int i=n-1;i>=0;i--){
        double ans;
        if(a!=0){
            ans=1+sgt.sum(i+a,i+b+1)/(b-a+1);
        }
        else{
            ans = ((b+1) + sgt.sum(i+1, i+b+1)) / b;
        }
        sgt.set(i,ans);
    }
    cout<<setprecision(10)<<sgt.sum(0,1);
    return 0;
}