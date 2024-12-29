#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

struct SegTree{
    int size;
    vector<pair<int,int>> cnt_min;//(m,c)

    pair<int,int> merge(pair<int,int> p1,pair<int,int> p2){
        if(p1.first==p2.first){
            return {p1.first,p1.second+p2.second};
        }
        else{
            if(p1.first<p2.first) return p1;
            else return p2;
        }
    }


    void build(vector<int>& a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()) cnt_min[x]={a[lx],1};
            return;
        }
        int m=(lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        cnt_min[x]=merge(cnt_min[2*x+1],cnt_min[2*x+2]);

    }

    SegTree(vector<int>& a){
        int n=a.size();
        size=1;
        while(size<n) size*=2;
        cnt_min.assign(2*size,{INT_MAX,0});
        build(a,0,0,size);
    }
    void set(int i,int val,int x,int lx,int rx){
        if(rx-lx==1){
            cnt_min[x] = {val, 1};
            return;
        }
        int m=(lx+rx)/2;
        if(i<m){
            set(i,val,2*x+1,lx,m);
        }
        else{
            set(i,val,2*x+2,m,rx);
        }
        cnt_min[x]=merge(cnt_min[2*x+1],cnt_min[2*x+2]);
    }

    void set(int i,int val){
        set(i,val,0,0,size);
    }

    pair<int,int> getMC(int l,int r,int x,int lx,int rx){
        if(rx<=l || lx>=r) return {INT_MAX,0};
        if(l<=lx && rx<=r){
            return cnt_min[x];
        }
        int m=(lx+rx)/2;
        return merge(getMC(l,r,2*x+1,lx,m),getMC(l,r,2*x+2,m,rx));
    }

    pair<int,int> getMC(int l,int r){
        return getMC(l,r,0,0,size);
    }
};


int main()
{
fastio;
    int n,m;cin>>n>>m;
    vector<int> a(n);for(auto &i:a) cin>>i;
    SegTree sgt(a);
    while(m--){
        int op,a,b;cin>>op>>a>>b;
        if(op==1){
            sgt.set(a,b);
        }
        else{
            auto p=sgt.getMC(a,b);
            cout<<p.first<<" "<<p.second<<"\n"; 
        }
    }
    return 0;
}