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
       set<int> unmatched;
       for(int i=1;i<=n;i++) unmatched.insert(i);
       set<pair<int,int>> edges;//{u,v} u<v
       // gets the k where the path is only singleton={u}
       int k,q;
       auto getMink=[&](int u){
        vector<int> tgt(1,u);
        int lo=1,hi=(1<<30),ansk=-1;
            while(lo<hi){
                int mid=(lo+hi)/2;
                // ask
                cout<<"? "<<mid<<endl;
                cin>>q;
                vector<int> ls(q);
                for(auto &i:ls) cin>>i;

                // compare
                if(ls==tgt){
                    ansk=mid;
                    break;
                }
                else if(ls>tgt){
                    hi=mid-1;
                }
                else{
                    lo=mid+1;
                }
            }
            return ansk;
       };
        int q=2,k=2;// k=1 is node-1 only
       while(unmatched.size()){
            // b.s. for minm k s.t. path starts from a given u
            int u=*unmatched.begin();
            k=getMink(u)+1;
            vector<int> ls(1,u);
            // get all edges in the connected component of u
            while(ls[0]==u){
                // ask
                cout<<"? "<<k<<endl;
               cin>>q;
               if(q==0) break;
               ls.assign(q,-1);
               for(auto &i:ls) cin>>i;

               for(int i=1;i<q;i++){
                int u=ls[i-1],v=ls[i];
                unmatched.erase(u);
                unmatched.erase(v);
                edges.emplace(u,v);
               }
               k++;
            }
       }
       // print
       cout<<"! "<<edges.size()<<endl;
       for(auto [u,v]:edges){
        cout<<u<<' '<<v<<endl;
       }
    }
    return 0;
}