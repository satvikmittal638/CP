#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
struct query{
    int l,r,c;
    query(int ml,int mr,int mc){
        l=ml;
        r=mr;
        c=mc;
    }
};
// DSU
vector<int> parent,rnk,nxt;// nxt stores the nearest uncolored cell to the right
void make_set(int v){
    parent[v]=v;
    rnk[v]=0;
    nxt[v]=v;
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
        // a is deeper tree now
        parent[b] = a;
        nxt[a]=max(nxt[b],nxt[a]);
        if (rnk[a] == rnk[b]) rnk[a]++;
    }
}
int main()
{
fastio;
    int n,q;cin>>n>>q;
    vector<query> qs;
    while(q--){
        int l,r,c;cin>>l>>r>>c;l--;r--;
        qs.emplace_back(l,r,c);
    }
    reverse(all(qs));
    vector<int> a(n);
    // Initialize DSU
    parent.assign(n+1,0);nxt.assign(n+1,0);rnk.assign(n+1,0);
    for(int i=0;i<=n;i++) make_set(i);

    // process in reverse
    for(auto q:qs){
        // this works in O(alpha(n)) with rank heuerestics
        for(int i=nxt[find_set(q.l)];i<=q.r;i=nxt[find_set(i)]){
            a[i]=q.c;
            union_sets(i,i+1);
        }
    }
    for(auto e:a) cout<<e<<'\n';
    return 0;
}