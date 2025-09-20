#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll INF=1e18;
vector<vector<pair<int,ll>>> adj;
vector<bool> hasHorse;
void djikstra(vector<vector<ll>>& d,int s){
    auto cmp=[&](auto &a,auto &b){
        return make_pair(d[a.first][a.second],a)<make_pair(d[b.first][b.second],b);
    };
    set<pair<int,int>,decltype(cmp)> q(cmp);
    /*
    d[u][0] is the shortest distance from s to u w/o horse
    d[u][1] is ... with horse
    */
    d[s][0]=0ll;
    q.insert({s,0}); // start without a horse
    while(q.size()){
        auto [u,cur_state]=*q.begin();
        q.erase(q.begin());

        bool onHorse=cur_state||hasHorse[u]; // 1 if I am currently on the horse or can climb on it from the current node
        for(auto &[v,w]:adj[u]){
            ll dist=onHorse?w/2:w;
            // improve the distance
            if(d[u][cur_state] + dist<d[v][onHorse]){
                q.erase({v,onHorse});
                d[v][onHorse]=d[u][cur_state] + dist;
                q.insert({v,onHorse}); // now insertion takes place with updated distance comparison in the comparators
            }
        }
    }
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,m,h;cin>>n>>m>>h;
       hasHorse.assign(n,0);
       for(int i=0;i<h;i++){
        int x;cin>>x;x--;
        hasHorse[x]=1;
       }
       adj.assign(n,vector<pair<int,ll>>());
       while(m--){
        int u,v;ll w;cin>>u>>v>>w;u--;v--;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
       }
       vector<vector<ll>> d1(n,vector<ll>(2,INF)),d2(n,vector<ll>(2,INF));
       djikstra(d1,0);
       djikstra(d2,n-1);   
       // now try all possible meeting nodes
       // no explcit handling for when both reach a vertex with horse and both of them try to take it
       // i.e. only 1 horse is sufficient for each node for them to reach an optimal meeting time
       ll ans=INF;
       for(int i=0;i<n;i++){
        ll t1=min(d1[i][0],d1[i][1]), t2=min(d2[i][0],d2[i][1]);
        ans=min(ans,max(t1,t2));
       }
       if(ans>=INF) ans=-1;
       cout<<ans<<"\n";

    }
    return 0;
}