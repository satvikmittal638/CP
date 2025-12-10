#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
using pii=pair<int,int>;
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
       string s,tmps;cin>>s;tmps=s;
       int n=s.size();
       int q;cin>>q;
       vector<pii> qs;
       while(q--){
        int t,i;cin>>t>>i;
        qs.emplace_back(t,i);
       }
       for(auto &[t,i]:qs){
        // apply all type-2 queries
        if(t==2){
            s[i]='#';
        }
       }
       reverse(all(qs));
       // make connected blocks now
       //Initialize dsu
       parent.assign(n,0);
       rnk.assign(n,0);
       sz.assign(n,0);
       for(int i=0;i<n;i++) make_set(i);
       for(int i=0;i<n-1;i++){
        if(s[i]=='#') continue;
        if(s[i]==s[i+1]) union_sets(i,i+1);
       }
       vector<int> ans;
       for(auto &[t,i]:qs){
        if(t==1){
            ans.push_back(sz[find_set(i)]);
        }
        else{
            // undo the opn
            s[i]=tmps[i];
            if(i>0 && s[i]==s[i-1])union_sets(i-1,i);
            if(i<n-1 && s[i]==s[i+1]) union_sets(i,i+1);
        }
       }
       reverse(all(ans));
       cout<<"Case "<<z<<":\n";
       for(auto e:ans) cout<<e<<'\n';
    }
    return 0;
}