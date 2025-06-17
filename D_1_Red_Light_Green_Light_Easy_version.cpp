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
       int n,k;cin>>n>>k;
       vector<ll> p(n),d(n);
       for(auto &i:p) cin>>i;
       for(auto &i:d) cin>>i;
       int q;cin>>q;
       while(q--){
        ll a;cin>>a;
        // emulate the process
        int dir=1;
        ll t=0ll;
        // reach the first traffic light
        int i=lower_bound(all(p),a)-p.begin(); 
        if(i>=n) {
            cout<<"YES\n";
            continue;
        }
        set<pair<int,pair<int,int>>> states;
        bool ok=1;
        // O(n^2) in worst case
        while(i>=0 && i<n){
            t+=p[i]-a;
            a=p[i];
            bool color=(t%k==d[i]); // 1 for red, 0 for green
            pair<int,pair<int,int>> cur_state={i,{color,dir}};
            // state repeated->cycle formed
            if(states.count(cur_state)){
                ok=0;
                break;
            }
            states.insert(cur_state);
            if(color){
                dir*=-1; // flip the dirn
            }
            i+=dir;
        }
        cout<<(ok?"YES":"NO")<<"\n";
       }
    }
    return 0;
}