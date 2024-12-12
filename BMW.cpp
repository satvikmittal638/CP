#include<bits/stdc++.h>
using namespace std;
class UnionFind {
private:
    vector<int> p, rank;

public:
    UnionFind(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i;
    }


    int findSet(int i) {
        if (p[i] != i) {
            p[i] = findSet(p[i]);  //compress the path
        }
        return p[i];
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    // rank heurestic + path compression
    void unite(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) 
                p[y] = x;
            else {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};
class Edge{
    public:
        int u,v;
        long long wt;
    Edge(int u1, int v1, long long wt1) {
        u=u1;v=v1;wt=wt1;
    }
    bool operator<(const Edge& other) const{
        return wt<other.wt;
    }
};
int main()
{
    int tt;cin>>tt;
    while(tt--){
        int n,m;cin>>n>>m;
        vector<Edge> edges;
       UnionFind uf(n+1);
        while(m--){
            int a,b;
            long long v;
            cin>>a>>b>>v;
            Edge e(a,b,v);
            edges.emplace_back(e);
        }
        sort(edges.rbegin(),edges.rend()); // sort in descending to make Maxm ST
        long long maxSpeed=-1;
        for(const auto& e:edges){
            uf.unite(e.u,e.v);
// as soon as 1 and n are connected, the last edge used is the minm of all edges used 
//and is maximized by use of maxm spanning tree
            if(uf.isSameSet(1,n)){
                maxSpeed=e.wt;
                break;
            }
        }
        cout<<maxSpeed<<"\n";
    }
    return 0;
}