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
       int n;cin>>n;
       set<int> seen;
       int ans=0;
       while(n--){
        int u,v;cin>>u>>v;
        if(seen.count(u)==0 && seen.count(v)==0){
            ans++;
        }
        seen.insert(u);seen.insert(v);
       }
       cout<<ans<<"\n";
    }
    return 0;
}