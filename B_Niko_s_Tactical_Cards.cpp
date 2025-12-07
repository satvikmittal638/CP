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
       vector<ll> a(n+1,0ll),b(n+1,0ll);
       // dp1 for max, dp2 for min
       vector<vector<ll>> dp1(n+1,vector<ll>(2,0ll)),dp2(n+1,vector<ll>(2,0ll));
       for(int i=1;i<=n;i++) cin>>a[i];
       for(int i=1;i<=n;i++) cin>>b[i];
       for(int i=1;i<=n;i++){
        dp1[i][0]=max(dp1[i-1][0],dp1[i-1][1])-a[i];
        dp1[i][1]=b[i]-min(dp2[i-1][0],dp2[i-1][1]);

        dp2[i][0]=min(dp2[i-1][0],dp2[i-1][1])-a[i];
        dp2[i][1]=b[i]-max(dp1[i-1][0],dp1[i-1][1]);
       }
       cout<<max(dp1[n][0],dp1[n][1])<<'\n';
    }
    return 0;
}