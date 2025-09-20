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
       vector<int> b(n);
       vector<vector<int>> invb(n+1,vector<int>());
       for(int i=0;i<n;i++){
        cin>>b[i];
        invb[b[i]].push_back(i);
       }
       bool ok=1;
       vector<int> ans(n,0);
       int e=1;
       for(int i=1;i<=n;i++){
        if(invb[i].size()%i!=0){
            ok=0;
            break;
        }
        // OW split these into grps of sizes i each
        for (int j=0; j<invb[i].size(); j+=i) {
            for (int k=0;k<i;k++) {
                ans[invb[i][j+k]]=e;
            }
            e++;
        }
       }
       if(ok){
        for(auto e:ans) cout<<e<<' ';
       }
       else{
        cout<<-1;
       }
       cout<<'\n';


    }
    return 0;
}