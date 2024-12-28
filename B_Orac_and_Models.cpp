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
       vector<int> s(n+1),dp(n+1,0);
       for(int i=1;i<=n;i++)cin>>s[i];
    //    dp[0]=0;
       for(int i=1;i<=n;i++){
        // check divisors of i(not equal to i)
        int mx=INT_MIN;
        if(s[1]<s[i]) mx=dp[1];
        for(int j=2;j*j<=i;j++){
            if(i%j==0) {
                int d1=j,d2=i/j;
                if(s[d1]<s[i]) mx=max(mx,dp[d1]);
                if(s[d2]<s[i]) mx=max(mx,dp[d2]);
            }
        }
        dp[i]=1+(mx==INT_MIN?0:mx);
       }

       int ans=*max_element(all(dp));
       cout<<ans<<"\n";
    }
    return 0;
}