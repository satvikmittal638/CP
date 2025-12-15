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
    
    map<string, ll> memo;
    // BFS function in part-1 worked by chance :), its indeed incorrect
    // DFS function
    function<ll(string, string)> count_paths = [&](string u, string target) -> ll {
        if (u == target) return 1;          // Reached the target
        if (memo.count(u)) return memo[u];  // Return cached answer

        ll sum = 0;
        if (adj.count(u)) {
            for (const string& v : adj[u]) {
                sum += count_paths(v, target);
            }
        }
        return memo[u] = sum;
    };

    auto paths = [&](string from, string to) {
        memo.clear();
        return count_paths(from, to);
    };
    // svr->dac->fft->out
    // svr->fft->dac->out
    cout<<(paths("svr","dac")*paths("dac","fft")*paths("fft","out") + paths("svr","fft")*paths("fft","dac")*paths("dac","out"));
    return 0;
}