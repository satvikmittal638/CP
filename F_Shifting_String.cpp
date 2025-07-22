#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

void dfs(vector<vector<ll>>& adj,vector<bool>& vis,vector<ll>& cycle,ll u){
    vis[u]=1;
    for(auto v:adj[u]){
        if(!vis[v]) {
            cycle.push_back(v);
            dfs(adj,vis,cycle,v);
        }
    }
}
int main()
{
fastio;
    ll tt;cin>>tt;
    while(tt--){
       ll n;cin>>n;
       string s;cin>>s;
       vector<vector<ll>> adj(n,vector<ll>());
       // build directed permutation graph
       for(ll i=0;i<n;i++){
        ll x;cin>>x;x--;
        adj[i].push_back(x);
       }
       vector<bool> vis(n,0);
       ll ans=1;
       for(ll i=0;i<n;i++){
        if(vis[i]) continue;
        // get the connected cycle in order
        vector<ll> cycle;
        cycle.push_back(i);
        dfs(adj,vis,cycle,i);
        // for(auto e:cycle) cout<<e<<" ";
        // cout<<"\n";
        // construct the string from the cycle
        string tmp,cyclic_tmp;
        for(auto j:cycle) tmp+=s[j];
        cyclic_tmp=tmp+tmp; // for ease in cyclic shifting
        // find minm k so that tmp shifted k times is same as tmp
        ll sz=tmp.size();
        ll cycle_len = sz;// by default a 360 rotation
        for(ll j=1;j<sz;j++){
            string shifted=cyclic_tmp.substr(j,sz);
            if(shifted==tmp){
                cycle_len = j;
                break;
            }
        }
        ans = lcm(cycle_len, ans);
       }
       cout << ans << "\n";

    }
    return 0;
}