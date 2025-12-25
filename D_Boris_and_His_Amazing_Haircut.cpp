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
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n),b(n);
       for(auto &i:a) cin>>i;
       for(auto &i:b) cin>>i;
       int m;cin>>m;
       vector<int> x(m);for(auto &i:x) cin>>i;
        // preliminary checks
        bool ok=1;
        // Check1-can't grow hairs
        for(int i=0;i<n;i++){
            if(a[i]<b[i]){
                ok=0;break;
            }
        }
        if(!ok){
            cout<<"NO\n";
            continue;
        }
        SegTree sgtb(b);
       map<int,vector<int>> needyInds;// b[i]->{indices which need to be cut to be exactly of length b[i]}
       for(int i=0;i<n;i++){
        if(a[i]>b[i]) needyInds[b[i]].push_back(i);
       }
       // compress x
       map<int,int> f_x;
       for(int i=0;i<m;i++){
        f_x[x[i]]++;
       }
       // merge blocks and maintain their count
    for(auto const& [raz, inds] : needyInds){
        int f = f_x[raz]; // number of available razors of this size
        if (inds.empty()) continue;

        int cntBlocks = 1; // need at least one razor for the first index
        for(int j = 1; j < inds.size(); j++){
            // if there's a value in b between two required positions 
            // that is greater than the razor size, we must start a new segment.
            if(sgtb.getmax(inds[j-1] + 1, inds[j]) > raz){
                cntBlocks++;
            }
        }

        if(cntBlocks > f){
            ok = 0;
            break;
        }

       }
       cout<<(ok?"YES":"NO")<<'\n';
    }
    return 0;
}