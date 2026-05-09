#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

#ifndef ONLINE_JUDGE
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
#else
#define error(args...)
#endif

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,m;cin>>n>>m;
       vector<vector<int>> adj1(n),adj2(n);
       vector<int> indeg(n,0),outdeg(n,0);
       while(m--){
        int u,v;cin>>u>>v;u--;v--;
        adj1[u].push_back(v);
        adj2[v].push_back(u);
        indeg[v]++;
        outdeg[u]++;
       }
       vector<bool> isPartOfCycle(n,1);
       queue<int> q;

       // peeling off using indeg
       for(int i=0;i<n;i++) if(indeg[i]==0)q.push(i);

       while(q.size()){
        int u=q.front();q.pop();
        isPartOfCycle[u]=0;
        for(auto v:adj1[u]){
            indeg[v]--;
            if(indeg[v]==0) q.push(v);
        }
       }

       // peeling off using outdeg
       for(int i=0;i<n;i++) if(outdeg[i]==0) q.push(i);

       while(q.size()){
        int u=q.front();q.pop();
        isPartOfCycle[u]=0;
        for(auto v:adj2[u]){
            outdeg[v]--;
            if(outdeg[v]==0) q.push(v);
        }
       }
       cout<<accumulate(all(isPartOfCycle),0)<<'\n';
       
    }
    return 0;
}