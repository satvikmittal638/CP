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
       for(int i=1;i<=n;i++) cin>>a[i];
       vector<bool> dp(n+1,0);
       dp[0]=1;
       /*
       dp[i] denotes if segment [0,i-1] is valid or not
       */
      for(int i=1;i<=n;i++){
        if(i+a[i]<=n && dp[i-1]) dp[i+a[i]]=1;
        if(i-a[i]-1>=0 && dp[i-a[i]-1]) dp[i]=1; 
      }
      cout<<(dp[n]?"YES":"NO")<<"\n";
      
    }
    return 0;
}