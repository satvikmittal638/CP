#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

struct SegTree{
    int size;
    vector<int> maxs;
 
    void build(vector<int>& a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()){
                maxs[x]=a[lx];
            }
            return;
        }
        int m=(lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        maxs[x]=max(maxs[2*x+1],maxs[2*x+2]);
    }
 
    SegTree(vector<int>& a){
        int n=a.size();
        size=1;
        while(size<n)size*=2;
        maxs.assign(2*size,INT_MIN);
        build(a,0,0,size);
    }
 
    void set(int i,int val,int x,int lx,int rx){
        if(rx-lx==1){
            maxs[x]=val;
            return;
        }
        int m=(lx+rx)/2;
        if(i<m){
            set(i,val,2*x+1,lx,m);
        }else{
            set(i,val,2*x+2,m,rx);
        }
        maxs[x]=max(maxs[2*x+1],maxs[2*x+2]);
    }
 
    void set(int i,int val){
        set(i,val,0,0,size);
    }
   
    int getmax(int l,int r,int x,int lx,int rx){
        if(lx>=r || rx<=l){
            return INT_MIN;
        }
        if(l<=lx && rx<=r){
            return maxs[x];
        }
        int m=(lx+rx)/2;
        return max(getmax(l,r,2*x+1,lx,m),getmax(l,r,2*x+2,m,rx));
    }
    int getmax(int l,int r){
        return getmax(l,r,0,0,size);
    }
 
};
 

int main()
{
fastio;
    int n,m;cin>>n>>m;
    vector<int> a(m);for(auto &i:a) cin>>i;
    SegTree sgt(a);
    int q;cin>>q;
    while(q--){
        int xs,ys,xf,yf,k;cin>>xs>>ys>>xf>>yf>>k;ys--;yf--;
        if(abs(yf-ys)%k!=0 || abs(xf-xs)%k!=0){
            cout<<"NO\n";continue;
        }
        // reach the maxm height possible
        xs+=((n-xs)/k)*k;
        int maxHeight = sgt.getmax(min(ys, yf), max(ys, yf) + 1);
        if(xs <= maxHeight){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
    }
    return 0;
}