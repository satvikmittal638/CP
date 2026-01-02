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

struct SegTree{
    int size;
    vector<pair<int,int>> mins;

    void build(vector<pair<int,int>>& a,int x,int lx,int rx){
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

    SegTree(vector<pair<int,int>>& a){
        int n=a.size();
        size=1;
        while(size<n)size*=2;
        mins.assign(2*size,{INT_MAX,INT_MAX});
        build(a,0,0,size);
    }

    void set(int i,pair<int,int> val,int x,int lx,int rx){
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

    void set(int i,pair<int,int> val){
        set(i,val,0,0,size);
    }
   
    pair<int,int> getMin(int l,int r,int x,int lx,int rx){
        if(lx>=r || rx<=l){
            return {INT_MAX,INT_MAX};
        }
        if(l<=lx && rx<=r){
            return mins[x];
        }
        int m=(lx+rx)/2;
        return min(getMin(l,r,2*x+1,lx,m),getMin(l,r,2*x+2,m,rx));
    }
    pair<int,int> getMin(int l,int r){
        return getMin(l,r,0,0,size);
    }

};
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n);
       vector<pair<int,int>> amin,amax;
       vector<vector<int>> inva(n+1);
       for(auto &i:a) cin>>i;
       for(int i=0;i<n;i++){
           inva[a[i]].emplace_back(i);
           amin.emplace_back(a[i],i);
           amax.emplace_back(-a[i],i);
        }
        set<int> minOfLastInds;
        for(int i=1;i<=n;i++){
            if(inva[i].empty()) continue;
            minOfLastInds.insert(inva[i].back());
        }
        vector<int> ans;
        int i=0;
        SegTree sgtMin(amin),sgtMax(amax);
       while(minOfLastInds.size() && i<n){
        int j=*minOfLastInds.begin();// smallest suffix [j,n] s.t. it has all reqd elts
        int add;
    
        // odd size->for even idx, choose minm reqd a[k] with minm k, i<=k<=j
        if(ans.size()&1){
           auto [mn,mnInd]=sgtMin.getMin(i,j+1);
           add=mn;
           i=mnInd+1;
        }
        // even size->for odd idx, choose maxm reqd a[k] with minm k, i<=k<=j
        else{
            auto [mx,mxInd]=sgtMax.getMin(i,j+1);
            add=abs(mx);
            i=mxInd+1;
        }
        // update both segtrees to deactivate the elt we have added in the subsequence
        for(auto ind:inva[add]){
            sgtMin.set(ind,{INT_MAX,INT_MAX});
            sgtMax.set(ind,{INT_MAX,INT_MAX});
        }
        ans.push_back(add);
        minOfLastInds.erase(inva[add].back()); // this elt is done, so remove it
       }
       cout<<ans.size()<<'\n';
       for(auto e:ans) cout<<e<<' ';
       cout<<'\n';
    }
    return 0;
}