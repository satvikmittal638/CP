#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

int x=-1,y=-1;
int n;
vector<vector<int>> adj;

// Bridge Finding
void ISNOT_BRIDGE(int v,int to){
    if(x!=-1) return;
    if(adj[v].size()>=4){
        x=v;y=to;
    }
    else if(adj[to].size()>=4){ // Check the other node too
        x=to;y=v;
    }
}

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = 1;
    tin[v] = low[v] = timer++;
    bool parent_skipped = 0;
    for (int to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = 1;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
            // Back-edge is also part of a cycle
            ISNOT_BRIDGE(v, to);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] <= tin[v])
                ISNOT_BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, 0);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

int main()
{
    fastio;
    int tt;cin>>tt;
    while(tt--){
       x=-1; y=-1;
       
       int m;cin>>n>>m;
       adj.assign(n,vector<int>());
       while(m--){
        int u,v;cin>>u>>v;u--;v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
       }
       
       find_bridges();
       
       if(x==-1){
        cout<<"NO\n";
        continue;
       }
       
       // x has deg>=4
       // find shortest path from y back to x IGNORING direct edge x-y
        queue<int> q;
        vector<bool> used(n, 0);
        vector<int> p(n, -1);

        // Start BFS from y
        q.push(y);
        used[y] = 1;
        p[y] = -1;
        

        bool found = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            
            if(v == x) { found = 1; break; }

            for (int u_node : adj[v]) {
                // Ignore the direct edge back to x from y
                if (v == y && u_node == x) continue;

                if (!used[u_node]) {
                    used[u_node] = 1;
                    q.push(u_node);
                    p[u_node] = v;
                }
            }
        }

        if(!found) { cout<<"NO\n"; continue; }

        // recover the path starting from x back to y
        vector<int> path;
        for (int v = x; v != -1; v = p[v])
            path.push_back(v);
        // path is now: x -> parent of x -> ... -> y
        
        cout<<"YES\n";
        cout<<path.size()+2<<'\n'; // path edges + 2 fins
        
        // ngbrs of x in the cycle are y and path[1] (node after x in vector)
        int u1 = y;
        int u2 = (path.size() > 1) ? path[1] : -1;
        
        // find 2 vertex which is neither of u1 or u2
        int cnt=0;
        for(auto v:adj[x]){
            if(cnt>=2) break;
            if(v!=u1 && v!=u2){
                cout<<x+1<<' '<<v+1<<'\n'; // 1-based
                cnt++;
            }
        }
        
        // print the cycle
        cout<<x+1<<' '<<y+1<<'\n'; // direct edge
        for(int i=0; i<path.size()-1; i++){
            cout<<path[i]+1<<' '<<path[i+1]+1<<'\n'; // 1-based
        }
    }
    return 0;
}