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
const int INF=1e9;
int main()
{
fastio;
    int n,m,k;cin>>n>>m>>k;
    vector<vector<int>> adj(n);
    while(m--){
        int x,y;cin>>x>>y;x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    set<vector<int>> blocked;
    while(k--){
        int a,b,c;cin>>a>>b>>c;a--;b--;c--;
        blocked.insert({a,b,c});
    }
    queue<pair<int,int>> q;// {prev node,cur node}
    vector<vector<bool>> vis(n,vector<bool>(n,0));
    vector<vector<int>> d(n,vector<int>(n,INF));

    map<pair<int,int>,pair<int,int>> par;
    d[0][0]=0;
    q.emplace(-1,0);
    while(q.size()){
        auto [prev,cur]=q.front();
        q.pop();
        for(auto v:adj[cur]){
            if(vis[cur][v] || blocked.count({prev,cur,v})>0) continue;
            vis[cur][v]=1;
            int prevDist = (prev == -1 ? 0 : d[prev][cur]);
            d[cur][v] = prevDist + 1;
            par[{cur,v}]={prev,cur};
            q.emplace(cur,v);
        }
    }
    int ans=INF,tail=-1;
    for(int i=0;i<n;i++){
        if(d[i][n-1]<ans){
            ans=d[i][n-1];
            tail=i;
        }
    }
    if(ans>=INF) {
        cout<<"-1";
        return 0;
    }
    cout<<ans<<'\n';
    pair<int,int> cur={tail,n-1};
    vector<int> path;
    while(cur.first!=-1){
        path.push_back(cur.second+1);
        cur=par[cur];
    }
    path.push_back(1);
    reverse(all(path));
    for(auto v:path) cout<<v<<' ';
    return 0;
}