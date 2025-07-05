#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()


struct SegTree{
    int size;
    vector<int> gcds;
 
    void build(vector<ll>& a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()){
                gcds[x]=a[lx];
            }
            return;
        }
        int m=(lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        gcds[x]=gcd(gcds[2*x+1],gcds[2*x+2]);
    }
 
    SegTree(vector<ll>& a){
        int n=a.size();
        size=1;
        while(size<n)size*=2;
        gcds.assign(2*size,0);
        build(a,0,0,size);
    }
 
    void set(int i,int val,int x,int lx,int rx){
        if(rx-lx==1){
            gcds[x]=val;
            return;
        }
        int m=(lx+rx)/2;
        if(i<m){
            set(i,val,2*x+1,lx,m);
        }else{
            set(i,val,2*x+2,m,rx);
        }
        gcds[x]=gcd(gcds[2*x+1],gcds[2*x+2]);
    }
 
    void set(int i,int val){
        set(i,val,0,0,size);
    }
   
    int getgcd(int l,int r,int x,int lx,int rx){
        if(lx>=r || rx<=l){
            return 0;
        }
        if(l<=lx && rx<=r){
            return gcds[x];
        }
        int m=(lx+rx)/2;
        return gcd(getgcd(l,r,2*x+1,lx,m),getgcd(l,r,2*x+2,m,rx));
    }
    int getgcd(int l,int r){
        return getgcd(l,r,0,0,size);
    }
 
};

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,q;cin>>n>>q;
       vector<ll> a(n),dif;for(auto &i:a) cin>>i;
       for(int i=1;i<n;i++){
        dif.push_back(abs(a[i]-a[i-1]));
       }
       SegTree sgt(dif);
       while(q--){
        int l,r;cin>>l>>r;l--;r--;
        cout<<sgt.getgcd(l,r)<<" ";
       }
       cout<<"\n";
    }
    return 0;
}