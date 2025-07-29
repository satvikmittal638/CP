#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

struct SegTree{
    ll size;
    vector<ll> tree;
    ll NEUTRAL;
 
 
    void build(vector<ll>& a,ll x,ll lx,ll rx){
        if(rx-lx==1){
            if(lx<(ll)a.size()) {
                // update leaf node
                tree[x]=a[lx];
            }
            return;
        }
        ll m=(lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        tree[x]=tree[2*x+1]+tree[2*x+2];
 
    }
 
    SegTree(vector<ll>& a){
        ll n=a.size();
        size=1;
        NEUTRAL=0; 
        while(size<n) size*=2;
        tree.assign(2*size,NEUTRAL);
        build(a,0,0,size);
    }
    void set(ll i,ll val,ll x,ll lx,ll rx){
        if(rx-lx==1){
            tree[x] = val; // update the leaf node
            return;
        }
        ll m=(lx+rx)/2;
        if(i<m){
            set(i,val,2*x+1,lx,m);
        }
        else{
            set(i,val,2*x+2,m,rx);
        }
        tree[x]=tree[2*x+1]+tree[2*x+2];
    }
 
    void set(ll i,ll val){
        set(i,val,0,0,size);
    }
 
    ll calc(ll l,ll r,ll x,ll lx,ll rx){
        //Case-1:current segment doesn't llersect with required segment
        if(lx>=r || l>=rx)return 0ll;
    //Case-2:current segment is contained inside the required segment
        if(lx>=l && rx<=r) return tree[x];
        ll m=(lx+rx)/2;
        ll s1=calc(l,r,2*x+1,lx,m); // get required calc from left subtree
        ll s2=calc(l,r,2*x+2,m,rx);// get required calc from right subtree
        return s1+s2;
    }
 
    ll calc(ll l,ll r){
        return calc(l,r,0,0,size);
    }
};


// Helper function to count inversions using SegTree and coordinate compression
ll countInversions(vector<ll>& arr) {
    ll n = arr.size();
    vector<ll> sorted = arr;
    sort(sorted.begin(), sorted.end());
    map<ll, ll> compress;
    for (ll i = 0; i < n; ++i)
        compress[sorted[i]] = i;

    vector<ll> freq(n, 0);
    SegTree sgt(freq);
    ll inv_count = 0;
    for (ll i = n - 1; i >= 0; --i) {
        ll idx = compress[arr[i]];
        inv_count += sgt.calc(0, idx);
        sgt.set(idx, sgt.calc(idx, idx + 1) + 1);
    }
    return inv_count;
}

int main()
{
    fastio;
    ll tt; cin >> tt;
    while (tt--) {
        ll n; cin >> n;
        vector<ll> a(n), b(n);
        multiset<ll> msa, msb;
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
            msa.insert(a[i]);
        }
        for (ll i = 0; i < n; i++) {
            cin >> b[i];
            msb.insert(b[i]);
        }

        if (msa != msb) {
            cout << "NO\n";
            continue;
        }

        ll inv_a = countInversions(a);
        ll inv_b = countInversions(b);

        cout << ((inv_a % 2 == inv_b % 2) ? "YES" : "NO") << "\n";
    }
    return 0;
}