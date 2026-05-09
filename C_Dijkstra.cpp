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
const ll INF=1e18;
int main()
{
fastio;
    int n,m;cin>>n>>m;
    vector<vector<pair<int,ll>>> adj(n);
    while(m--){
        ll a,b,w;cin>>a>>b>>w;a--;b--;
        adj[a].emplace_back(b,w);
        adj[b].emplace_back(a,w);
    }

    vector<int> p(n,-1);
    vector<ll> d(n,INF);
    d[0]=0;
    set<pair<int,int>> q;
    q.emplace(0,0);//{w,u}
    while(q.size()){
        int v=q.begin()->second;
        q.erase(q.begin());
        for(auto edge:adj[v]){
            auto [to,len]=edge;
            if(d[v]+len<d[to]){
                q.erase({d[to],to});
                d[to]=d[v]+len;
                p[to]=v;
                q.emplace(d[to],to);
            }
        }
    }
    if(d[n-1]>=INF){
        cout<<"-1\n";
        return 0;
    }
    // trace back
    vector<int> path;
    for(int v=n-1;v!=-1;v=p[v]){
        path.push_back(v+1);
    }
    reverse(all(path));
    for(auto e:path) cout<<e<<' ';
    return 0;
}