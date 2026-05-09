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
const int N=3005;
vector<vector<int>> adj,radj;
// length of path is no. of nodes on it

// recl(u) is length of longest path starting at node u
int dpl[N];
int recl(int u){
    // base 
    // if(adj[u].size()==0) return 0;
    // cache check
    if(dpl[u]!=-1) return dpl[u];
    
    // compute and save
    int ans=1;// self node included by default
    for(auto v:adj[u]){
        ans=max(ans,recl(v)+1);
    }
    return dpl[u]=ans;
}

// recr(u) is length of longest path ending at node u
int dpr[N];
int recr(int u){
    // base 
    // if(radj[u].size()==0) return 1;
    // cache check
    if(dpr[u]!=-1) return dpr[u];
    
    // compute and save
    int ans=1;// self node included by default
    for(auto v:radj[u]){
        ans=max(ans,recr(v)+1);
    }
    return dpr[u]=ans;
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<ll> a(n),b(n),c(n);
       for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i];
       adj.assign(n,vector<int>());
       radj.assign(n,vector<int>());
       // build the DAG
       for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            // difference is not quadratic
            if(a[i]==a[j]){
                if(b[i]==b[j]){
                    if(c[i]<c[j]){
                        adj[i].emplace_back(j);
                        radj[j].emplace_back(i);
                    }
                    else if(c[i]>c[j]){
                        adj[j].emplace_back(i);
                       radj[i].emplace_back(j);
                    }
                }
                // O.W. always intersect
            }
            // difference is quadratic
            else{
                ll D=(b[i]-b[j])*(b[i]-b[j])-4*(a[i]-a[j])*(c[i]-c[j]);
                if(D>=0) continue;
                // f[i]>f[j]
                // j->i is an edge
                if(a[i]>a[j]){
                    adj[j].emplace_back(i);
                    radj[i].emplace_back(j);
                }
                // i->j is an edge
                else{
                    adj[i].emplace_back(j);
                    radj[j].emplace_back(i);
                }
            }
        }
       }
       // now since we imposed strict ordering
       // find longest path in DAG having a node i(this is unique)
       for(int i=0;i<n;i++) dpl[i]=dpr[i]=-1;
       for(int i=0;i<n;i++){
        cout<<(recl(i)+recr(i)-1)<<' ';
       }
       cout<<'\n';
       
    }
    return 0;
}