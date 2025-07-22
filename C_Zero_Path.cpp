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
       for(int i=0;i<n;i++) for(int j = 0; j < m; ++j) cin >> a[i][j];
       
       vector<vector<int>> mn(n,vector<int>(m,INT_MAX)),mx(n,vector<int>(m,INT_MIN));
       mn[0][0]=mx[0][0]=a[0][0];
       // base casing
       for(int i=1;i<n;i++) {
        mn[i][0]=mx[i][0]=mx[i-1][0]+a[i][0];
       }
       for(int i=1;i<m;i++) {
        mn[0][i]=mx[0][i]=mx[0][i-1]+a[0][i];
       }
       for(int i=1;i<n;i++)
        for(int j=1;j<m;j++){
                mn[i][j]=min(mn[i-1][j],mn[i][j-1])+a[i][j];
                mx[i][j]=max(mx[i-1][j],mx[i][j-1])+a[i][j];
        }
       
       // if 0 not lies in the range
       // or path sum is odd
       if(mx[n-1][m-1]%2!=0 || mn[n-1][m-1] > 0 || mx[n-1][m-1] < 0){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
    return 0;
}