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

struct Query {
    int i, j, x;
};

int main()
{
fastio;
    int n,q;cin>>n>>q;
    
    vector<Query> queries(q);
    for(int k=0; k<q; k++){
        cin >> queries[k].i >> queries[k].j >> queries[k].x;
        queries[k].i--; queries[k].j--; // 0-indexed
    }

    vector<vector<int>> adjs(n);
    vector<bool> forbidden(n);
    vector<int> ans(n,0);

    for(int pos = 0; pos < 30; pos++){
        // clear for current bit
        for(int i=0; i<n; i++) {
            adjs[i].clear();
            forbidden[i] = 0;
        }

        int mask=(1<<pos);

        // rebuild graph/forbidden for this bit only
        // this improves caching
        for(const auto& qry : queries){
            // set bit, add an edge
            if(qry.x & mask){
                adjs[qry.i].push_back(qry.j);
                adjs[qry.j].push_back(qry.i);
            }
            // 0 is fixed at both indices i and j, so u can't make them 0 in any case
            // but still the constraints to have or=1 involving them will exist
            else{
                forbidden[qry.i]=forbidden[qry.j]=1;
            }
        }

        // try to keep as many 0s as possible on starting from the beginning
        for(int idx = 0; idx<n; idx++){
            // can't use this
            if(forbidden[idx]) continue;
            bool take=0;
            for(auto u:adjs[idx]){
                // self loop
                if(u==idx){
                    take=1;break;
                }
                // neighbour on the other side of the edge is forced to take a 0
                // so u must now take a 1 to satisfy the constraint
                if(forbidden[u]){
                    take=1;break;
                }
                // already processed ngbr u has a 0, so now we must have a 1
                if(u<idx && (ans[u]&mask)==0){
                    take=1;break;
                }
            }
            if(take){
                ans[idx]|=(1<<pos);
            }
            
        }
    }
    for(auto e:ans) cout<<e<<' ';
    return 0;
}