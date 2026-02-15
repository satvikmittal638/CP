#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

struct SegTree{
    int size;
    vector<int> mins;
 
    void build(vector<int>& a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()){
                mins[x]=a[lx];
            }
            return;
        }
        int m=(lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        mins[x]=min(mins[2*x+1],mins[2*x+2]);
    }
 
    SegTree(vector<int>& a){
        int n=a.size();
        size=1;
        while(size<n)size*=2;
        mins.assign(2*size,INT_MAX);
        build(a,0,0,size);
    }
 
    void set(int i,int val,int x,int lx,int rx){
        if(rx-lx==1){
            mins[x]=val;
            return;
        }
        int m=(lx+rx)/2;
        if(i<m){
            set(i,val,2*x+1,lx,m);
        }else{
            set(i,val,2*x+2,m,rx);
        }
        mins[x]=min(mins[2*x+1],mins[2*x+2]);
    }
 
    void set(int i,int val){
        set(i,val,0,0,size);
    }
   
    int getMin(int l,int r,int x,int lx,int rx){
        if(lx>=r || rx<=l){
            return INT_MAX;
        }
        if(l<=lx && rx<=r){
            return mins[x];
        }
        int m=(lx+rx)/2;
        return min(getMin(l,r,2*x+1,lx,m),getMin(l,r,2*x+2,m,rx));
    }
    // gets minm of [l,r)
    int getMin(int l,int r){
        return getMin(l,r,0,0,size);
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
       while(q--){
        int idx;cin>>idx;
        if(idx==1){
            int i,x;cin>>i>>x;i--;
            sgt.set(i,x);
            a[i]=x;
        }
        else{
            int l,r;cin>>l>>r;l--;r--;
            // nastiness is either 0 or 1
            // B.S. for d when g(d)=min(a[l,l+d])-d becomes 0
            // g(d) is monotonically decreasing fn of increasing d
            int lo=0,hi=r-l,ans=0;
            while(lo<=hi){
                int d=(lo+hi)/2;
                int g=sgt.getMin(l,l+d+1)-d;
                // cerr<<g<<' ';
                // decrease d->increase g
                if(g<0){
                    hi=d-1;
                }
                // increase d->decrease g
                else if(g>0){
                    lo=d+1;
                }
                else{
                    ans=1;
                    break;
                }
            }
            // cerr<<'\n';
            cout<<ans<<'\n';
        }
       }
    }
    return 0;
}