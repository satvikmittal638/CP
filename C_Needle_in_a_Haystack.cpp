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
       string s,t;cin>>s>>t;
       multiset<char> mst;
       for(auto c:t) mst.insert(c);
       bool ok=1;
       for(auto c:s){
        if(mst.count(c)>0) mst.erase(mst.find(c));
        else{
            ok=0;
            break;
        }
       }
       if(!ok){
        cout<<"Impossible\n";
        continue;
       }
       vector<vector<char>> beforePosInS(s.size(),vector<char>());
       int i=0;
       while(i<s.size()){
        while(mst.size() && *mst.begin()<s[i]){
            beforePosInS[i].push_back(*mst.begin());
            mst.erase(mst.begin());
        }
        i++;
       }
       for(int i=0;i<s.size();i++){
        for(auto c:beforePosInS[i]) cout<<c;
        cout<<s[i];
       }
       for(auto c:mst) cout<<c;
       cout<<'\n';
    }
    return 0;
}