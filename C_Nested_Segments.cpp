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
        NEUTRAL=0; // empty segment is allowed so we can use 0
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

    int find(int k,int x,int lx,int rx){
        if(rx-lx==1){
            return lx;
        }
        int sum_left=tree[2*x+1];
        int m=(lx+rx)/2;
        // for 0-indexing, strictly <
        if(k<sum_left){
            return find(k,2*x+1,lx,m);
        }
        else{
            return find(k-sum_left,2*x+2,m,rx);
        }
    }

    int find(int k){
        return find(k,0,0,size);
    }

};


int main()
{
fastio;
    int n;cin>>n;
    vector<int> a(2*n),visited(2*n),leftBorder(n+1,-1),ans(n);
    for(auto &i:a) cin>>i;
    SegTree sgt(visited);
    for(int i=0;i<2*n;i++){
        // left border was seen, so now we reached the right border
        if(leftBorder[a[i]]!=-1){
            ans[a[i]-1]=sgt.calc(leftBorder[a[i]],i+1);
            sgt.set(leftBorder[a[i]],1); // update the left border visited
        }
        else{
            leftBorder[a[i]]=i;
        }
    }
    for(auto e:ans)cout<<e<<" ";
    return 0;
}