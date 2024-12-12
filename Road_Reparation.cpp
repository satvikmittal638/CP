#include<bits/stdc++.h>
using namespace std;
vector<int> linker,sz;

int find(int a){
    while(a!=linker[a]){
        a=linker[a];
    }
    return a;
}

void unite(int a,int b){
    a=find(a);b=find(b);
    if(a!=b){
        if(sz[a]<sz[b]) swap(a,b);
        sz[a]+=sz[b];
        linker[b]=a;
    }
}

bool isSameSet(int a,int b){
    a=find(a);b=find(b);
    return a==b;
}
int getSize(int a){
    return sz[find(a)];
}
struct Edge{
    int u,v,wt;
    Edge(int u, int v, int wt) : u(u), v(v), wt(wt) {}
    bool operator<(const Edge& other) const{
        return wt<other.wt;
    }
};

int main()
{
    int n,m;cin>>n>>m;
    linker.assign(n+1,0);sz.assign(n+1,1);
    for(int i=0;i<=n;i++) linker[i]=i;

    long long minCost=0,cnt_edges=0;
    vector<Edge> edges;
    while(m--){
        int a,b,c;cin>>a>>b>>c;
        edges.emplace_back(a,b,c);
    }
    sort(edges.begin(),edges.end());
    for(auto e:edges){
        if(!isSameSet(e.u,e.v)){
            minCost+=e.wt;
            cnt_edges++;
            unite(e.u,e.v);
        }
    }
    if(cnt_edges==n-1)
        cout<<minCost;
    else
        cout<<"IMPOSSIBLE";
    return 0;
}