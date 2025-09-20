#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
vector<int> d;
vector<vector<int>> adj;
vector<int> parent;
void dfs(int u,int par){
    parent[u] = par;
    for(auto v : adj[u]){
        if(v == par) continue;
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       adj.assign(n,vector<int>());
       for(int i=1;i<n;i++) {
           int u,v;cin>>u>>v;u--;v--;
           adj[u].push_back(v);
           adj[v].push_back(u);
        }
        parent.assign(n,-1);
        d.assign(n,0);
        dfs(0,-1); // root tree at 0
        // find farthest node from the root
        int mx1=max_element(all(d))-d.begin();
        parent.assign(n,-1);
        d.assign(n,0);
        dfs(mx1,-1);// now find the farthest node from that node -> mx1->start is a diameter
        int start=max_element(all(d))-d.begin();
        // build on_diameter vector
        vector<int> on_diameter(n, 0);
        for(int u=start; u!=-1; u=parent[u]){
            on_diameter[u] = 1;
        }
        // now trace back the diameter to find respective nodes
        int a=-1,b=-1,c=-1;
        for(int u=start; u!=-1; u=parent[u]){
            if(adj[u].size() >= 3){
                for(auto v : adj[u]){
                    if(!on_diameter[v]){
                        b = u;
                        a = parent[u];
                        c = v;
                        break;
                    }
                }
            }
            if(c != -1) break;
        }
        if(a != -1 && b != -1 && c != -1){
            cout << (a+1) << " " << (b+1) << " " << (c+1) << '\n';
        } else {
            cout << "-1\n";
        }


    }
    return 0;
}