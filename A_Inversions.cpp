#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
struct SegTree{
    int size;
    vector<int> tree;
    int NEUTRAL;


    void build(vector<int>& a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()) {
                // update leaf node
                tree[x]=a[lx];
            }
            return;
        }
        int m=(lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        tree[x]=tree[2*x+1]+tree[2*x+2];

    }

    SegTree(vector<int>& a){
        int n=a.size();
        size=1;
        NEUTRAL=0; 
        while(size<n) size*=2;
        tree.assign(2*size,NEUTRAL);
        build(a,0,0,size);
    }
    void set(int i,int val,int x,int lx,int rx){
        if(rx-lx==1){
            tree[x] = val; // update the leaf node
            return;
        }
        int m=(lx+rx)/2;
        if(i<m){
            set(i,val,2*x+1,lx,m);
        }
        else{
            set(i,val,2*x+2,m,rx);
        }
        tree[x]=tree[2*x+1]+tree[2*x+2];
    }

    void set(int i,int val){
        set(i,val,0,0,size);
    }

    int calc(int l,int r,int x,int lx,int rx){
        //Case-1:current segment doesn't intersect with required segment
        if(lx>=r || l>=rx)return 0ll;
    //Case-2:current segment is contained inside the required segment
        if(lx>=l && rx<=r) return tree[x];
        int m=(lx+rx)/2;
        ll s1=calc(l,r,2*x+1,lx,m); // get required sum from left subtree
        ll s2=calc(l,r,2*x+2,m,rx);// get required sum from right subtree
        return s1+s2;
    }

    int calc(int l,int r){
        return calc(l,r,0,0,size);
    }

    

   

};
int main()
{
fastio;
    int n;cin>>n;
    vector<int> a(n);
    SegTree sgt(a);
    for(int i=0;i<n;i++) {
        int a;cin>>a;a--;
        cout<<sgt.calc(a+1,n)<<" ";
        sgt.set(a,1);
    }
    return 0;
}