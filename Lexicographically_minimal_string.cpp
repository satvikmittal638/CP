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
        if (rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
    }
}
int main()
{
fastio;
    string a,b,c;cin>>a>>b>>c;
    parent.assign(26,0);rnk.assign(26,0);
    for(int i=0;i<26;i++) make_set(i);
    for(int i=0;i<a.size();i++){
        union_sets(a[i]-'a',b[i]-'a');
    }
    vector<set<char>> sets(26);
    for(int i=0;i<26;i++){
        sets[find_set(i)].insert(i+'a');
    }
    for(int i=0;i<c.size();i++){
        c[i]=*sets[find_set(c[i]-'a')].begin();
    }
    cout<<c;

    return 0;
}