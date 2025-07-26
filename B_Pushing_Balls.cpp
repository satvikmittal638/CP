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
       vector<string> grid(n);for(auto &i:grid) cin>>i;
       bool ok=1;
       vector<vector<int>> p_row(n,vector<int>(m,0)),p_col(n,vector<int>(m,0));
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            p_row[i][j]+=(grid[i][j]-'0');
            if(j>0)p_row[i][j]+=p_row[i][j-1];

            p_col[i][j]+=(grid[i][j]-'0');
            if(i>0)p_col[i][j]+=p_col[i-1][j];
        }
       }
       for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(grid[i][j]=='1' && p_row[i][j-1]!=j && p_col[i-1][j]!=i){
                ok=0;
                break;
            }
        }
       }
      
       cout<<(ok?"YES":"NO")<<"\n";
    }
    return 0;
}