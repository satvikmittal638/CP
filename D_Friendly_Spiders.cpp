#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int MAX_A = 300005; // max value of a[i]
const int MAX_N = 300005; // max value of n

int main()
{
    fastio;
    // Precompute smallest prime factor via SOE
    vector<int> mn_pf(MAX_A + 1);
    iota(all(mn_pf), 0);
    for(int i = 2; i * i <= MAX_A; i++){
        if(mn_pf[i] == i) { // If i is a prime
            for(int j = i * i; j <= MAX_A; j += i){
                if(mn_pf[j] == j){ // Set smallest prime factor only once
                    mn_pf[j] = i;
                }
            }
        }
    }

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int s, t;
    cin >> s >> t;

    // trivial case where start and end are the same
    if (s == t) {
        cout << 1 << "\n" << s << "\n";
        return 0;
    }

    // A Bipartite Graph: spider nodes (1..n) and prime nodes (n+1..n+MAX_A)
    vector<vector<int>> adj(n + MAX_A + 1);
    for (int i = 1; i <= n; i++) {
        int val = a[i];
        while (val > 1) {
            int p = mn_pf[val];
            // Edge between spider 'i' and prime 'p'
            adj[i].push_back(n + p);
            adj[n + p].push_back(i);
            while (val % p == 0) {
                val /= p;
            }
        }
    }

    // BFS on the new graph
    queue<int> q;
    vector<int> p(n + MAX_A + 1, 0); // 0 to indicate no parent
    vector<bool> used(n + MAX_A + 1, 0);
    
    q.push(s);
    used[s] = 1;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        if (v == t) break; // stop if target is found

        for(auto u : adj[v]){
            if(!used[u]){
                used[u] = 1;
                q.push(u);
                p[u] = v;
            }
        }
    }

    // check if a path was found and restore it
    if (!used[t]) {
        cout << -1 << "\n";
    } else {
        vector<int> path;
        for (int v = t; v != 0; v = p[v]) {
            // only add spider nodes to the final path
            if (v <= n) {
                path.push_back(v);
            }
        }
        reverse(all(path));

        cout << path.size() << "\n";
        for(auto e:path) {
            cout <<e<<" ";
        }
        cout << "\n";
    }

    return 0;
}