#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int MAX=2*1e4+2;
// DSU
vector<int> parent,rnk,sz;
void make_set(int v){
    parent[v]=v;
    rnk[v]=0;
    sz[v]=1;
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v]=find_set(parent[v]);
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
int size(int a){
    return sz[find_set(a)];
}
int main()
{
fastio;
    int tt;cin>>tt;
    for(int z=1;z<=tt;z++){
       int n;cin>>n;
       parent.assign(2*MAX,0);
       sz.assign(2*MAX,0);
       rnk.assign(2*MAX,0);
       for(int i=0;i<2*MAX;i++) make_set(i);
       // make bipartite sets
       // color 1 till MAX, other color 2 from MAX+1 to 2*MAX
       while(n--){
        int a,b;cin>>a>>b;
        if(size(a+MAX)>1 || size(b)>1) union_sets(a+MAX,b);//a in color-2 or b in color-1
        else union_sets(a,b+MAX);// a in color-1 or b in color-2 or no prvs binding
      }
       // save only sizes of color-1 elts from each bipartite set
       vector<ll> sizesOfColor1(2*MAX,0);
       for(int i=0;i<MAX;i++){
        sizesOfColor1[find_set(i)]++;// store sizes at the representative of the set
       }
       ll ans=0ll;
       for(int i=0;i<MAX;i++){
        if(sz[i]<=1) continue;// isolated
        ans+=max(sizesOfColor1[i],sz[i]-sizesOfColor1[i]); // choose maxm sized color from a bipartite set
       }
       cout<<"Case "<<z<<": "<<ans<<'\n';
       
    }
    return 0;
}