#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n+1,vector<int>());
    while(m--){
        int u,v;cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<bool> visited(n+1,0);
    set<int> st;
    st.insert(1);
    while(!st.empty()){
        int top=*st.begin();
        st.erase(st.begin());
        visited[top]=1;
        cout<<top<<" ";
        for(auto nbr:adj[top]){
            if(!visited[nbr])
                st.insert(nbr);
        }
    }
    return 0;
}