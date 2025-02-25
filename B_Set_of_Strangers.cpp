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
       int n,m;cin>>n>>m;
       map<int,vector<pair<int,int>>> mp; // color->set of coordinates
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int c;cin>>c;
            mp[c].push_back({i,j});
        }
       }
       int ans=mp.size()-1;
       for(auto p:mp){
        set<pair<int,int>> st;
        for(auto [i,j]:p.second){
            // if a neighbour is found, this coordinate is dealt in a different set
            if(st.count({i+1,j}) || st.count({i-1,j}) || st.count({i,j+1}) || st.count({i,j-1})){
                ans++;
            }
            st.insert({i,j});
        }
       }
       cout<<ans<<"\n";
       
    }
    return 0;
}