#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;cin>>n>>m;
    vector<string> grid(n);
    vector<vector<bool>> visited(n,vector<bool>(m,0));
    for(auto &i:grid) cin>>i; 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.') {
                if((i+j)&1) grid[i][j]='W';
                else grid[i][j]='B';
            }
        }
    }

    for(auto s:grid) cout<<s<<"\n";
    return 0;
}