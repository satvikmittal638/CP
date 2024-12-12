#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> paths;
vector<bool> visited;

void dfs(int v, int depth, int parent) {
    visited[v] = true;

    bool isLeaf = true; // Assume this node is a leaf
    for (auto u : adj[v]) {
        if (u != parent) { // Skip the parent
            isLeaf = false; // Found a child
            dfs(u, depth + 1, v); // Pass parent as the current node
        }
    }

    if (isLeaf) { // If the node has no unvisited children, it's a leaf
        paths.push_back(depth);
    }
}

int main() {
    int n;
    cin >> n;
    adj.assign(n + 1, vector<int>()); // Adjust for 1-based indexing
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited.assign(n + 1, false);
    dfs(1, 0, -1); // Start DFS from node 1 with no parent (-1)

    float ans=(float)accumulate(paths.begin(),paths.end(),0)/(float)paths.size();
    printf("%.8f",ans);
    return 0;
}