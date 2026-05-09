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
// optimized to O(n)
// dp1[u] is maxm cost for subtree of r after performing atmost 1 opn
// dp2[u] is the cost w/o performing any opn
// ht[u] is height of subtree rooted at u
// subtreeSum[u] is sum of a[v] in subtree of u(excluding u itself)
vector<vector<int>> adj;
vector<ll> a,ht,subtreeSum,dp1,dp2;
void dfs1(int u,int p){
    for(auto v:adj[u]){
        if(v==p) continue;
        dfs1(v,u);// go down and compute everything for children
        // now use values of child
        ht[u]=max(ht[v]+1,ht[u]);
        subtreeSum[u]+=a[v]+subtreeSum[v];
        dp2[u]+=dp2[v];
    }
    dp2[u]+=subtreeSum[u];
}

void dfs2(int u,int p){

    for(auto v : adj[u]) {
        if(v == p) continue;
        dfs2(v, u);
    }
    /*
    2 cases, either we do opn inside subtrees of v or we do opn on v themselves
    both are handled seperately
    
    */
    ll mx1=0ll,sum2=0ll;
    // multiset<int> msh;// for external opn
    ll hmax1=-1ll,hmax2=-1ll;
    for(auto v:adj[u]){
        if(v==p) continue;
        mx1=max(mx1,dp1[v]-dp2[v]);// for internal opn
        sum2+=dp2[v];

        if(ht[v]>=hmax1){
            hmax2=hmax1;
            hmax1=ht[v];
        }
        else if(ht[v]>=hmax2){
            hmax2=ht[v];
        }
        // msh.insert(ht[v]);
    }
    ll base=sum2+subtreeSum[u];
    ll ans1=base+mx1,ans2=base;
    for(auto v:adj[u]){
        if(v==p) continue;
        // msh.erase(msh.find(ht[v])); // erase it to get maxm height amongst other subtrees
        ll mxh=hmax1;
        if(ht[v]==hmax1){
            // ll mxh=*msh.rbegin();
            // try moving subtree of v to another tree at its maxm height
            mxh=hmax2;
        }
        // to handle case where we have only 1 child v, so we can't shift to other
        if(mxh>=0) ans2=max(ans2,base+(mxh+1)*(a[v]+subtreeSum[v]));
        // msh.insert(ht[v]); // put it back
    }

    ans1=sum2+subtreeSum[u]+mx1;
    dp1[u]=max(ans1,ans2);
}



int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       // initialize
       a.assign(n,0);
       ht.assign(n,0);
       dp1.assign(n,0);
       dp2.assign(n,0);
       subtreeSum.assign(n,0);
       adj.assign(n,vector<int>());

       for(auto &i:a) cin>>i;
       for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;u--;v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
       }
       dfs1(0,-1);
       dfs2(0,-1);

       for(auto e:dp1) cout<<e<<' ';
       cout<<'\n';

    }
    return 0;
}