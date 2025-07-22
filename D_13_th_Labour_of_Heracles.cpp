#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       ll S=0ll;
       vector<pair<ll,int>> w(n);for(auto &i:w) {
        cin>>i.first;
        S+=i.first;
       }
       vector<vector<int>> adj(n,vector<int>());
       for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
       }
       for(int i=0;i<n;i++){
        w[i].second=adj[i].size();
       }
       sort(rall(w));
       ll ans=S;
       cout<<ans<<" ";
       for(int i=0;i<n-2;i++){
        ans+=w[i].first*(w[i].second-1);
        cout<<ans<<" ";
       }
       cout<<"\n";
       
    }
    return 0;
}