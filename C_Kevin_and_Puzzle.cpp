#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    const int MOD=998244353;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n);for(auto &i:a) cin>>i;
       a.insert(a.begin(),0); // make 1 indexed
       vector<int> dp(n+1,0);
       // base case;
       dp[0]=1;
        for(int i=1;i<=n;i++){
            // if i-1 is honest
            if(a[i]==a[i-1]) dp[i]+=dp[i-1];
            // if i-1 is liar
            if(i>1 && a[i]==a[i-2]+1) dp[i]+=dp[i-2];
            dp[i]%=MOD;
        } 
        int ans=(dp[n]+dp[n-1])%MOD;
        cout<<ans<<"\n";
    
    }
    return 0;
}