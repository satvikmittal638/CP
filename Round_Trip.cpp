#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v, int par) {
    visited[v] = true;
    for (auto u : adj[v]) {
        if (u == par) continue; // Skip edge to parent
        if (visited[u]) {
            cycle_start = u;
            cycle_end = v;
            return true; // Cycle found
        }
        parent[u] = v; // Assign parent
        if (dfs(u, v)) return true; // Pass the current node as the parent
    }
    return false; // No cycle found
}

int main() {
    int n, m;
    cin >> n >> m;

    // Initialize adjacency list
    adj.assign(n + 1, vector<int>());
    
    // Read edges
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    visited.assign(n + 1, false);
    parent.assign(n + 1, -1);
    cycle_start = 0;

    // Iterate through all vertices to handle disconnected components
    for (int v = 1; v <= n; v++) {
        if (!visited[v] && dfs(v, -1)) break;
    }

    if (cycle_start == 0) {
        cout << "IMPOSSIBLE\n"; // No cycle
    } else {
        vector<int> cycle;
        for (int v = cycle_end; v != cycle_start; v = parent[v]) {
            cycle.emplace_back(v);
        }
        cycle.emplace_back(cycle_start);
        cycle.emplace_back(cycle_end); // Close the cycle

        cout << cycle.size() << "\n";
        for (auto v : cycle) cout << v << " ";
        cout << endl;
    }

    return 0;
}