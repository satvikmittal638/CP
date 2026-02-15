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
vector<vector<int>> adj;
vector<int> c;
int main()
{
fastio;
    int n;cin>>n;
    adj.assign(n+1,vector<int>());
    vector<int> c(n+1);
    int r=-1;
    for(int i=1;i<=n;i++){
        int p;cin>>p>>c[i];
        if(p==0){
            r=i;
            continue;
        }
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    vector<int> nums(n+1);
    iota(all(nums),0);

    return 0;
}