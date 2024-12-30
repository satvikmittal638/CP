#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

struct item{
    ll sum;
    int mod2;
};


struct SegTree{
    int size;
    vector<item> tree;
    item NEUTRAL;
    item merge(item p1,item p2){
        ll sum;
        if(p1.mod2==0) sum=p1.sum+p2.sum;
        else sum=p1.sum-p2.sum;
        return {sum,(p1.mod2+p2.mod2)%2};
    }

    item single(int a){
        return {a,1};
    }
    //<===Don't modify below this line except NEUTRAL===>
    void build(vector<ll>& a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()) {
                // update leaf node
                tree[x]=single(a[lx]); 
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
        NEUTRAL={0,0};
        while(size<n) size*=2;
        tree.assign(2*size,NEUTRAL);
        build(a,0,0,size);
    }
    void set(int i,int val,int x,int lx,int rx){
        if(rx-lx==1){
            tree[x] = single(val); // update the leaf node
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
    int n,m;cin>>n;
    vector<ll> arr(n);for(auto &i:arr) cin>>i;
    SegTree sgt(arr);
    cin>>m;
    int type,a,b;
    while(m--){
        cin>>type>>a>>b;
        a--;
        if(type==0){
            sgt.set(a,b);
        }else{
            cout<<sgt.calc(a,b).sum<<"\n";
        }
    }
    return 0;
}