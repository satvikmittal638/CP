#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int MAX=1e5+2;
// DSU
vector<int> parent,rnk,sz,p_val,val_p;
void make_set(int v){
    parent[v]=v;
    rnk[v]=0;
    sz[v]=1;
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}
bool isSame(int x,int y){
    return find_set(x)==find_set(y);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        sz[a]+=sz[b];
        if (rnk[a] == rnk[b]) rnk[a]++;
    }
}
int main()
{
fastio;
    int tt;cin>>tt;
    for(int z=1;z<=tt;z++){
       int n,q;cin>>n>>q;
       parent.assign(n,0);
       rnk.assign(n,0);
       for(int i=0;i<n;i++) make_set(i);
    }
    return 0;
}