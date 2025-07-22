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
       vector<int> a(n);
       for(auto &i:a) {cin>>i;i--;}
       vector<vector<int>> inds(n,vector<int>());
       for(int i=0;i<n;i++){
        inds[a[i]].push_back(i);
       }
       vector<int> ans(n+1,-2);
       for(int x=0;x<n;x++){
        if(inds[x].empty()) continue;
        int mxDif=max(inds[x][0]+1,n-inds[x].back());
        for(int i=0;i<inds[x].size()-1;i++){
            mxDif=max(mxDif,inds[x][i+1]-inds[x][i]);
        }
        for(int k=mxDif;k<=n && ans[k]==-2;k++){
            ans[k]=x;
        }
       }
       for(int k=1;k<=n;k++) cout<<ans[k]+1<<" ";
       cout<<"\n";
    }
    return 0;
}