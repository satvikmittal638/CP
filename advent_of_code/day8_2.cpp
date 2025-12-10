#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
struct coord{
    ll x,y,z;
    coord(ll mx,ll my,ll mz){
        x=mx;
        y=my;
        z=mz;
    }
};
// DSU
vector<int> parent,rnk,sz;
int conn_comps;
void make_set(int v){
    parent[v]=v;
    rnk[v]=0;
    sz[v]=1;
}
int find_set(int v){
    if(v==parent[v]) return v;
    return parent[v]=find_set(parent[v]);
}
void union_sets(int a,int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(rnk[a]<rnk[b]) swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
        if(rnk[a]==rnk[b]) rnk[a]++;
        conn_comps--;
    }
}

int main()
{
fastio;
    vector<coord> crds;
    string line;

    while (getline(cin, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string sx, sy, sz;
        
        getline(ss, sx, ',');
        getline(ss, sy, ',');
        getline(ss, sz, ',');
        crds.emplace_back(stol(sx),stol(sy),stol(sz));
        
    }
    auto dist=[&](coord c1,coord c2){
        return (c1.x-c2.x)*(c1.x-c2.x) + (c1.y-c2.y)*(c1.y-c2.y) +(c1.z-c2.z)*(c1.z-c2.z);
    };
    // we have 1000 coords, so we can get pairwise euclidean disances
    vector<pair<ll,pair<int,int>>> dist_crdPair;
    for(int i=0;i<crds.size();i++){
        for(int j=i+1;j<crds.size();j++){
            dist_crdPair.push_back({dist(crds[i],crds[j]),{i,j}});
        }
    }
    sort(all(dist_crdPair));
    // DSU init
    int n=crds.size();
    parent.assign(n,0);
    rnk.assign(n,0);
    sz.assign(n,0);
    conn_comps=n;
    for(int i=0;i<n;i++) make_set(i);

    // unite smaller distances first
    int i=0;
    while(conn_comps>1){
        union_sets(dist_crdPair[i].second.first, dist_crdPair[i].second.second);
        i++;
    }
    i--;
    auto[m1,m2]=dist_crdPair[i].second;
    cout<<crds[m1].x*crds[m2].x;

    return 0;
}