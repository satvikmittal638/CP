#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll INF=1e18;
const int MAX=1000;
vector<vector<pair<int,ll>>> adj;
vector<ll> s;

// d[i][s] is the shortest time to reach city i, with s being the minimum slowness among all bikes owned.
void djikstra(int st,vector<vector<ll>>& d){
    // The comparator for the set, ordering by distance first, then by state.
    auto cmp=[&](const pair<int, int>& a, const pair<int, int>& b){
        // Compare distances
        if (d[a.first][a.second] != d[b.first][b.second]) {
            return d[a.first][a.second] < d[b.first][b.second];
        }
        // Break ties using the state itself
        return a < b;
    };
    set<pair<int,int>,decltype(cmp)> q(cmp); // State: (city, min_slowness)
    
    // Initial state: at city 0 (1-indexed), must buy bike s[0]. Time is 0.
    d[0][s[0]]=0;
    q.insert({0,(int)s[0]});

    while(!q.empty()){
        auto [u, k] = *q.begin();
        q.erase(q.begin());

        // if we found a shorter path to this state already, skip.
        if (d[u][k] > d[u][k]) continue;

        for(auto &[v,w]:adj[u]){
            // travel time from u to v is determined by the best bike you currently own (slowness k).
            ll curT = d[u][k] + w * (ll)k; 
            
            // upon arriving at v, you buy the local bike. Your new best slowness is min(k, s[v]).
            ll mn_s = min((ll)k, s[v]);

            // if this path is a better way to reach state (v, mn_s), update it.
            if(curT < d[v][mn_s]){
                q.erase({v, (int)mn_s});
                d[v][mn_s] = curT;
                q.insert({v, (int)mn_s});
            }
        }
    }
}

int main()
{
    fastio;
    int tt;cin>>tt;
    while(tt--){
        int n,m;cin>>n>>m;
        adj.assign(n,vector<pair<int,ll>>());
        for(int i=0; i<m; ++i){
            int u,v;ll w;cin>>u>>v>>w;u--;v--;
            adj[u].emplace_back(v,w);
            adj[v].emplace_back(u,w);
        }
        s.assign(n,0);for(auto &i:s) cin>>i;
        vector<vector<ll>> d(n,vector<ll>(MAX+1,INF));
        djikstra(0,d);

        cout<<*min_element(all(d[n-1]))<<"\n";
    }
    return 0;
}