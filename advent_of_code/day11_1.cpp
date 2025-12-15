#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    map<string, vector<string>> adj;
    string line;

    while (getline(cin, line)) {
        if (!line.size()) continue;

        auto p = line.find(':');
        string key = line.substr(0, p);
        string rest = line.substr(p + 1);

        stringstream ss(rest);
        string w;
        vector<string> v;
        while (ss >> w) v.push_back(w);
        adj[key] = v;
    }
    
    map<string,ll> dp; // dp[u] denotes no. of paths from 'you' to node u
    dp["you"]=1;// base case
    // run BFS
    queue<string> q;
    set<string> vis;
    q.push("you");
    while(q.size()){
        string u=q.front();q.pop();
        for(auto v:adj[u]){
            dp[v]+=dp[u];
            if(!vis.count(v)){
                q.push(v);
                vis.insert(v);
            }
        }
    }
    cout<<dp["out"];
    return 0;
}