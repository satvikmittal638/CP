#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

class DSU {
private:
    std::vector<int> parent, rank;
    int numSets; // Keeps track of the number of disjoint sets

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        numSets = n; // Initially, each element is its own set
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            numSets--; // Decrement the count of disjoint sets
        }
    }

    bool isSameSet(int x, int y) {
        return find(x) == find(y);
    }

    int getNumberOfSets() {
        return numSets;
    }
};

struct Edge{
    int u,v;
};

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,m1,m2;cin>>n>>m1>>m2;
       vector<Edge> edgesF;
       DSU dsuF(n),dsuG(n);
        while(m1--){
            int u,v;cin>>u>>v;
            u--;v--;
            edgesF.push_back({u,v});
        }
        while(m2--){
            int u,v;cin>>u>>v;
            u--;v--;
            dsuG.unite(u,v);
        }
        int ans=0;
        for(auto &e:edgesF){
            // if they belong to different connected components in G, break this edge
            if(!dsuG.isSameSet(e.u,e.v)){
                ans++;
                e.u=e.v=-1;// mark as invalid edge
            }
        }
        for(auto &e:edgesF){
            if(e.u!=-1){
                dsuF.unite(e.u,e.v);
            }
        }
/*
now no. of connected components of F>=G -> merge some vertices
*/
        ans+=dsuF.getNumberOfSets()-dsuG.getNumberOfSets();
        cout<<ans<<"\n";
    }
    return 0;
}