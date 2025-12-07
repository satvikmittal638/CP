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
       vector<vector<ll>> a(n+2,vector<ll>(n+2,0));
       int x=1;
       for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=x;
            x++;
        }
       }
       ll ans=0ll;
       for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
           ans=max(ans,a[i][j]+a[i-1][j]+a[i+1][j]+a[i][j-1]+a[i][j+1]);
        }
       }
       cout<<ans<<'\n';
    }
    return 0;
}