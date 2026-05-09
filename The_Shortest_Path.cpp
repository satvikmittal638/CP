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
       int n;cin>>n;
       vector<string> names;
       vector<pair<int,int>> toCost;
       for(int i=0;i<n;i++){
        string name;
        int p;
        cin>>name>>p;
        names.push_back(name);
        while(p--){
            int v,cost;cin>>v>>cost;v--;
            toCost.push_back
        }
       }
       map<string,int> invName;
       for(int i=0;i<n;i++) invName[names[i]]=i;
       vector<pair<int,int>> edges;
       for(auto [name,lst]:edgess){
        for(auto e:lst) edges.emplace_back(invName[name],e);
       }


       int r;cin>>r;
       while(r--){
        string name1,name2;cin>>name1>>name2;
        int u=invName[name1],v=invName[name2];

        // now run djikstra from 
       }
    }
    return 0;
}