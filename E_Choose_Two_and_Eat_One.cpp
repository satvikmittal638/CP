#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

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


long long modexp(long long base, long long exp, long long mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}


int main()
{
fastio;
    int n,m;cin>>n>>m;
    vector<int> a(n);for(auto &i:a) cin>>i;
    vector<Edge> edges;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int x=a[i],y=a[j],
                cost=(modexp(x,y,m)+modexp(y,x,m))%m;
            edges.emplace_back(i,j,cost);
        }
    }
    sort(rall(edges));
    // make Maxm ST
    UnionFind uf(n);
    ll score=0ll;
    for(const auto &e:edges){
        if(uf.findSet(e.u)!=uf.findSet(e.v)){
            score+=e.wt;
            uf.unite(e.u,e.v);
        }
    }
    cout<<score;
    return 0;
}