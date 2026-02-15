#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

// Source:CP-algorithms
vector<int> parent, sz;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

int size(int v){
    return sz[find_set(v)];
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main()
{
    fastio;
    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;
        vector<int> p(n); 
        for(auto &i : p) cin >> i;
        
        vector<int> d(n-1);
        vector<vector<int>> valToInd(n + 1);
        
        for(int i = 0; i < n - 1; i++){
            d[i] = abs(p[i] - p[i+1]);
            valToInd[d[i]].emplace_back(i);
        }

        auto cntSubarr = [&](ll l){
            return l * (l + 1) / 2;
        };

        // initialize DSU
        parent.assign(n, 0);
        sz.assign(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;

        ll ans = 0ll;
        vector<bool> active(n, 0);
        vector<ll> res;

        for(int k = n - 1; k >= 1; k--){
            for(auto i : valToInd[k]){
                active[i] = 1; 

                ll l = 0, r = 0;
                
                // check left neighbor
                if(i > 0 && active[i-1]) {
                    l = size(i-1);
                    union_sets(i, i-1);
                }
                // check right neighbor
                if(i < n-2 && active[i+1]) {
                    r = size(i+1);
                    union_sets(i, i+1);
                }
                
                ans -= cntSubarr(l);
                ans -= cntSubarr(r);
                ans += cntSubarr(l + r + 1);
            }
            res.push_back(ans);
        }

        reverse(all(res));
        for(auto x : res) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}