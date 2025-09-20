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
       int n,m,k;cin>>n>>m>>k;
       vector<vector<int>> ans(n,vector<int>(m,0));
       // print in natural reading order
       int z=0;
       for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++){
            ans[i][j]=(z%k)+1;
            z++;
        }
       }
       
       // cyclically shift alternating rows by 1 to avoid same-color adjacency
       if(m%k==0){
           for(int i = 1; i < n; i += 2) {
               for(int j = 0; j < m; j++) {
                   ans[i][j] = ans[i - 1][(j + 1) % m];
               }
           }
       }
       for(int i=0;i<n;i++) {
           for(int j=0;j<m;j++) cout<<ans[i][j]<<" ";
           cout<<"\n";
       }
    }
    return 0;
}