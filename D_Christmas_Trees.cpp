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
    int n,m;cin>>n>>m;
    vector<int> x(n);for(auto &i:x) cin>>i;
    set<int> vis;
    // start a multisource BFS from all the trees
    queue<pair<int,ll>> q; // {node,distance from nearest source}
    for(int i=0;i<n;i++){
        // add children
        vis.insert(x[i]);
        if(!vis.count(x[i]-1))q.emplace(x[i]-1,1);
        if(!vis.count(x[i]+1))q.emplace(x[i]+1,1);
    }
    ll res=0ll,cnt=0ll;
    vector<int> y;
    while(q.size() && cnt<m){
        auto [x,d]=q.front();q.pop();
        if(!vis.count(x)){
            vis.insert(x);
            y.emplace_back(x);
            res+=d;
            cnt++;
            // add its neigbours
            if(!vis.count(x-1)) q.emplace(x-1,d+1);
            if(!vis.count(x+1)) q.emplace(x+1,d+1);
        }
    }
    cout<<res<<'\n';
    for(auto e:y) cout<<e<<' ';
    return 0;
}