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
       vector<int> a(n+1);
       for(int i=1;i<=n;i++)cin>>a[i];
       /*
    dp[i][0] denote minm skip points on [1,i] with my chance next
    dp[i][1] denote minm skip points on [1,i] with friend's chance next
       */
       vector<vector<int>> dp(n+1,vector<int>(2,INT_MAX));
       dp[0][1]=0;
       
    }
    return 0;
}