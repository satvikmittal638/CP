#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;
        cin >> n;

        vector<vector<int>> adj(n+1,vector<int>());
        vector<int> deg(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    if(n<=2){
        cout<<"0\n";
        continue;
    }
    // find all leaves and cnt them
    vector<int> leaves;
    // rooted at 1
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            leaves.push_back(i);
        }
    }
    int total_leaves = leaves.size();

    // for each non-leaf node, cnt how many leaves its adj to
    vector<int> adj_leaf_cnt(n + 1, 0);
    for (int l : leaves) {
        // leaf has only one ngbr
        int ngbr = adj[l][0];
        adj_leaf_cnt[ngbr]++;
    }

    // find the maximum number of adj leaves for any single node
    int max_adj_leaves = *max_element(all(adj_leaf_cnt));
    cout << total_leaves - max_adj_leaves << '\n';
    // cout<<total_leaves<<"\n";
    }
    return 0;
}