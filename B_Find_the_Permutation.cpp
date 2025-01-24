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
       vector<string> g(n);
       for(auto &i:g) cin>>i;
       vector<int> ans(n,-1);
       for(int v=0;v<n;v++){
        int cnt_moreV=0,cnt_lessV=0;
        for(int j=0;j<v;j++){
            cnt_lessV+=g[v][j]=='1';
        }
        for(int j=v+1;j<n;j++){
            cnt_moreV+=g[v][j]=='1';
        }
        int idx=cnt_lessV+(n-v-1-cnt_moreV);
        ans[idx]=v+1;
       }
       for(auto e:ans) cout<<e<<" ";
       cout<<"\n";
    }
    return 0;
}