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
       map<int,int> mp;
       // compress
       for(int i=0;i<n;i++){
        int a;cin>>a;
        mp[a]++;
       }
       // unpack
       vector<int> as;
       for(auto &[k,v]:mp){
        as.emplace_back(k);
       }
       vector<int> ans;
       bool ok=1;
       for(int i=0;i<as.size();i++){
        // check the whole chain starting at this a
        if(mp[as[i]]>0 && mp[as[i]]<INT_MAX){
            int cnt=0;
            for(int j=as[i];j<=k;j+=as[i]){
                // same elt can be in multiple chains
                if(mp[j]>0){
                    cnt++;
                    mp[j]=INT_MAX;// to mark as used
                }
            }
            // chain can't start at this, so this a can never be in any chain, so no ans possible
            if(cnt<(k/as[i])){
                ok=0;
                break;
            }
            ans.push_back(as[i]);
        }
       }
       if(!ok){
        cout<<"-1\n";
        continue;
       }
       cout<<ans.size()<<'\n';
       for(auto e:ans) cout<<e<<' ';
       cout<<'\n';


    }
    return 0;
}