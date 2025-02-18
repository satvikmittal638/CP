#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int INF=1e9;
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n+1),ind(n+1);
       for(int i=1;i<=n;i++) {
        cin>>a[i];
        ind[a[i]]=i;
       }
       if(n<=2){
        cout<<"YES\n";continue;
       }
       if(!((a[1]==1 && a[n]==2) || (a[n]==1 && a[1]==2))){
            cout<<"NO\n";continue;
        }
        
        bool ok=1;
        map<int,set<pair<int,int>>> sgmts;// available length->set of {start,end} intervals
        sgmts[(n-1)-(2)].insert({2,n-1});
        for(int i=3;i<=n;i++){
            auto &[len,st]=*sgmts.rbegin(); // get largest interval
            bool foundAns=0;
            pair<int,int> seg; // tracks the segment where the ith person will be placed
            if(!foundAns){
                auto it=st.upper_bound({ind[i],INF});
                if(it!=st.begin()){
                    it--;
                    if(ind[i]<=it->second){
                        if(ind[i]==(it->first+it->second)/2 || ind[i]==(it->first+it->second+1)/2){
                            foundAns=1;
                            seg=*it;
                        }
                    }
                }
            }
            if(!foundAns){
                if(len%2==1 && sgmts.find(len-1)!=sgmts.end()){
                    set<pair<int,int>> &st=sgmts[len-1];
                    auto it=st.upper_bound({ind[i],INF});
                    if(it!=st.begin()){
                        it--;
                        if(ind[i]<=it->second){
                            if(ind[i]==(it->first+it->second)/2 || ind[i]==(it->first+it->second+1)/2){
                                foundAns=1;
                                seg=*it;
                            }
                        }
                    }
                }
            }
            if(!foundAns){
                ok=0;break;
            }
            sgmts[seg.second-seg.first].erase(seg);
            if(sgmts[seg.second-seg.first].empty()){
                sgmts.erase(seg.second-seg.first);
            }
            pair<int,int> seg1={seg.first,ind[i]-1},seg2={ind[i]+1,seg.second};
            if(seg1.second-seg1.first>=0) sgmts[seg1.second-seg1.first].insert(seg1);
            if(seg2.second-seg2.first>=0) sgmts[seg2.second-seg2.first].insert(seg2);
        }
        cout<<(ok?"YES":"NO")<<"\n";
        
    }
    return 0;
}