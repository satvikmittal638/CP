#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

typedef vector<vector<ll>> item;

ll r;
struct SegTree{
    int size;
    vector<item> tree;
    item NEUTRAL;
    item merge(const item &A, const item &B) {
        item result(2, vector<ll>(2, 0));
        for (int i = 0; i < 2; ++i) {
            for (int k = 0; k < 2; ++k) {
                ll temp = A[i][k];
                for (int j = 0; j < 2; ++j) {
                    result[i][j] = (result[i][j] + temp * B[k][j]) % r;
                }
            }
        }
        return result;
    }
    //<===Don't modify below this line except NEUTRAL===>
    void build(vector<item>& a,int x,int lx,int rx){
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
        tree[x]=merge(tree[2*x+1],tree[2*x+2]);

    }

    SegTree(vector<item>& a){
        int n=a.size();
        size=1;
        NEUTRAL={{1,0},
                  {0,1}
                  };
        while(size<n) size*=2;
        tree.assign(2*size,NEUTRAL);
        build(a,0,0,size);
    }
    void set(int i,item val,int x,int lx,int rx){
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
        tree[x]=merge(tree[2*x+1],tree[2*x+2]);
    }

    void set(int i,item val){
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
    int n,m;cin>>r>>n>>m;
    vector<item> mats(n,item(2,vector<ll>(2)));
    for(auto &i:mats) {
        for(int k=0;k<2;k++){
            for(int j=0;j<2;j++){
                cin>>i[k][j];
            }
        }
    }
    SegTree sgt(mats);

    while(m--){
        int l,r;cin>>l>>r;
        l--;
        item p=sgt.calc(l,r);
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                cout<<p[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}