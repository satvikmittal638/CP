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
       vector<string> grid(9);
       for(int i=0;i<9;i++){
        cin>>grid[i];
        for(int j=0;j<9;j++){
            if(grid[i][j]=='1') grid[i][j]='2';
        }
       }
       for(auto e:grid) cout<<e<<"\n";
    }
    return 0;
}