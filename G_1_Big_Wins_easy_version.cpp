#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

/*
gets minm in range [l,r)
both l and r are 0-indexed
*/
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
    int getMin(int l,int r){
        return getMin(l,r,0,0,size);
    }
};

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n);for(auto &i:a) cin>>i;
       SegTree sgt_a(a);
       int ans=INT_MIN;

       for(int m=1;m<=*max_element(all(a));m++){
        vector<int> cnt(n,0);// prefix array to track frequency of m in any subarray
        cnt[0]=a[0];
        for(int i=1;i<n;i++){
            cnt[i]=cnt[i-1]+(a[i]==m);
        }
        // stores the minm prefix end index l so that mn[pref[l]]=l
        vector<int> mn_l(2*n+1,INT_MAX); // store sum s as n+s (to deal with -ve sums)
        mn_l[n]=-1; // empty prefix
        SegTree sgt_mnl(mn_l);
        int cur=0; // current prefix sum(pref[r])
        for(int r=0;r<n;r++){
            cur+=(a[r]>=m)-(a[r]<m);// +1 for >=m, -1 for <m
            int min_l=sgt_mnl.getMin(0,cur+n+1); // get minm l so that pref[l-1]<=pref[r] --> necessary condition for m to be the median
            if(min_l!=INT_MAX){
                min_l++; // remove -1 from l-1
                int cntM=cnt[r]-(min_l>0?cnt[min_l-1]:0);// frequency of m in the given subarray
                // if m exists, then it will surely be the median of subarray [min_l,r]
                if(cntM>0){
                    int mn_elt=sgt_a.getMin(min_l,r+1);
                    ans=max(ans,m-mn_elt);
                }
            }
            // since we update mn_l in increasing order of indices, the 1st update is the minm l for a given target prefix sum
            if(mn_l[cur+n]==INT_MAX){
                mn_l[cur+n]=r;
                sgt_mnl.set(cur+n,r);
            }
        }
       }
       cout<<ans<<"\n";
    }
    return 0;
}