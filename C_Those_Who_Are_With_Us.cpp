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
       vector<vector<int>> a(n,vector<int>(m));
       vector<int> row_cnt_mx(n,0),col_cnt_mx(m,0);
       int mx=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            mx=max(mx,a[i][j]);
        }
       }
       int cntMax=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==mx){
                cntMax++;
                row_cnt_mx[i]++;
                col_cnt_mx[j]++;
            }
        }
       }
       int ans=mx;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int cur_cnt_mx=row_cnt_mx[i]+col_cnt_mx[j]-(a[i][j]==mx);
            if(cur_cnt_mx==cntMax){
                ans=mx-1;
                break;
            }
        }
       }
       cout<<ans<<"\n";

      
    }
    return 0;
}