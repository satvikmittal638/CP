#include <bits/stdc++.h>
using namespace std;

int dfs(int node, int parent, vector<vector<int>>& adjLst, vector<bool>& a, int m, int curConsecCat) {
    if (a[node]) curConsecCat++;
    else curConsecCat = 0;

    if (curConsecCat > m) return 0; // Path invalid if consecutive cats exceed m

    int isLeaf = 1; // Assume the node is a leaf initially
    int cnt_routes = 0;

    for (auto neighbor : adjLst[node]) {
        if (neighbor == parent) continue; // Avoid going back to the parent node
        isLeaf = 0; // If we have a valid child, it's not a leaf
        cnt_routes += dfs(neighbor, node, adjLst, a, m, curConsecCat);
    }

    return isLeaf ? 1 : cnt_routes; // If leaf, it's a valid route
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<bool> a(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x;
    }

    vector<vector<int>> adjLst(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adjLst[x].emplace_back(y);
        adjLst[y].emplace_back(x);
    }

    cout << dfs(1, 0, adjLst, a, m, 0) << endl;
    return 0;
}