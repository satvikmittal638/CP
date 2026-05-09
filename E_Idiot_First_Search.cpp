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
const int N=3*1e5+4;
const ll MOD=1e9+7;
int n;
vector<pair<int,int>> adj;
vector<int> p;

ll dp1[N];
// time taken to reach back to u starting from u
ll rec1(int u){
    // no children, i.e. leaf node
    if(adj[u]==make_pair(-1,-1)){
        return 0;
    }
    if(dp1[u]!=-1) return dp1[u];
    // go to left child, come back to it, then come back to u
    // now go to right child, come back to it, then come back to u
    return dp1[u]=((1+rec1(adj[u].first)+1)+(1+rec1(adj[u].second)+1))%MOD;
}

ll dp2[N];
// time take to reach 0 from node u
ll rec2(int u){
    // 0 to 0
    if(u<=0){
        return 0;
    }
    if(dp2[u]!=-1) return dp2[u];
    // come back to u , then move to its parent, and then move to 0 from there
    return dp2[u]=(rec1(u)+1+rec2(p[u]))%MOD;
}

int main()
{
    fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       adj.assign(n+1,pair<int,int>({-1,-1}));
       p.assign(n+1,-1);
       for(int i=1;i<=n;i++){
        int l,r;cin>>l>>r;
        if(l==0 && r==0) continue;
        adj[i]={l,r};
        p[l]=p[r]=i;
       }
       // initialize dps
        for(int i=0;i<=n;i++){
            dp1[i]=dp2[i]=-1;
        }
       for(int i=1;i<=n;i++){
        cout<<rec2(i)<<' ';
       }
       cout<<'\n';
    }
    return 0;
}