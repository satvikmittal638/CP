#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
// DSU
vector<int> parent,rnk;
void make_set(int v){
    parent[v]=v;
    rnk[v]=0;
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
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,k;cin>>n>>k;
       // initialize DSU
       /*
       store 3 possible states of a node i:
       i: grp A
       i+n:grp B
       i+2n:grp C
       */
       parent.assign(3*n,0);
       rnk.assign(3*n,0);
       for(int i=0;i<3*n;i++) make_set(i);

       int ans=0;
       //A->B->C->A
       while(k--){
        int d,x,y;cin>>d>>x>>y;x--;y--;
        if(x>=n || y>=n){
            ans++;
            continue;
        }
        if(d==1){
            // check if x eats y or y eats x
            if(isSame(x,y+n) || isSame(x+n,y)){
                ans++;
                continue;
            }
            union_sets(x,y);
            union_sets(x+n,y+n);
            union_sets(x+2*n,y+2*n);
        }
        else{
            // check if x and y in same set or y already eats x
            if(isSame(x,y) || isSame(y,x+n)){
                ans++;
                continue;
            }
            // x->y
            // y is food for x
            // the group x eats is same as the grp y is in
            union_sets(x,y+n);
            union_sets(x+n,y+2*n);
            union_sets(x+2*n,y);

        }
       }
       cout<<ans<<'\n';
    }
    return 0;
}