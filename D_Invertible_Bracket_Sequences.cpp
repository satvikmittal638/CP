#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

#ifndef ONLINE_JUDGE
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
#else
#define error(args...)
#endif

// Segtree
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
        int n;
       string s;cin>>s;
       n=s.length();
       s=' '+s;//1-indexed
       vector<int> p(n+1,0ll);
       vector<vector<int>> sumToInd(n+1);
       sumToInd[0].push_back(0);// empty prefix
       for(int i=1;i<=n;i++){
        p[i]=p[i-1]+(s[i]=='(')-(s[i]==')');
        sumToInd[p[i]].push_back(i);
       }
       SegTree sgt(p);
       ll ans=0ll;
       for(int s=0;s<=n;s++){
        for(int i=0;i<sumToInd[s].size();i++){
            int l=sumToInd[s][i];
            // find maxm index z s.t. max(p[i]) for l<=i<=l[z] <= 2*p[l]
            // use B.S. on z
            int lo=i+1,hi=sumToInd[s].size()-1,idx=-1;
            while(lo<=hi){
                int mid=(lo+hi)/2;
                // compute maxm of p[i] on [l,sumToInd[s][mid]]using segtree
                int mx=sgt.getmax(l+1,sumToInd[s][mid]+1);
                
                // this z doesn't work
                // try to decrease z
                if(mx>2*p[l]){
                    hi=mid-1;
                }
                // this z works
                // but try to increase z
                else{
                    idx=mid;
                    lo=mid+1;
                }
            }
            if(idx>i){
                // all zs from [i+1,idx] work
                ans+=idx-i;
            }
            
        }
       }
       cout<<ans<<'\n';
       
    }
    return 0;
}