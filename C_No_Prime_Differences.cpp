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
       vector<vector<int>> ans(n,vector<int>(m));
       // put first n/2 rows in odd rows
       int ctr=1;
       for(int i=1;i<n;i+=2){
        for(int j=0;j<m;j++){
            ans[i][j]=ctr;
            ctr++;
        }
       }
       // put last n/2 rows in even rows
       for(int i=0;i<n;i+=2){
        for(int j=0;j<m;j++){
            ans[i][j]=ctr;
            ctr++;
        }
       }
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
       }
    }
    return 0;
}