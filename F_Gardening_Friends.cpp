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

vector<vector<int>> adj;
vector<int> d,down,up,mx1Sib,mx2Sib;

void dfs1(int u,int p){
    for(auto v:adj[u]){
        if(v==p) continue;
        d[v]=d[u]+1;// update distance from root
        dfs1(v,u);// compute hts for all children below
        down[u]=max(down[u],down[v]+1);// now compute height for current node

// compute maxm and 2nd maxm value of down[v] for all v which are ngbrs of u
        int val = down[v] + 1;
        if(val > mx1Sib[u]){
            mx2Sib[u] = mx1Sib[u];
            mx1Sib[u] = val;
        }
        else if(val > mx2Sib[u]){
            mx2Sib[u] = val;
        }
    }
}

void dfs2(int u,int p){
    for(auto v:adj[u]){
        if(v==p) continue;
        int mxSib=mx1Sib[u];
        // longest path involves this node v, so take the 2nd longest path which would not involve this node v
        if(mxSib==(down[v]+1)) mxSib=mx2Sib[u];
        up[v]=1+max(up[u],mxSib);
        dfs2(v,u);
    }
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       ll n,k,c;cin>>n>>k>>c;
      adj.assign(n,vector<int>());
       for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
       }
       d.assign(n,0);//distance from original root 0
       down.assign(n,0);
       mx1Sib.assign(n,-1);
       mx2Sib.assign(n,-1);
       dfs1(0,-1);

       up.assign(n,0);
       dfs2(0,-1);
       // try all roots
       ll ans=-1ll;
       for(int r=0;r<n;r++){
        ans=max(ans,k*max(down[r],up[r])-d[r]*c);
       }
       cout<<ans<<'\n';


       
    }
    return 0;
}