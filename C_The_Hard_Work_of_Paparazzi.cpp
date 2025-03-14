#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int r,n;cin>>r>>n;
    vector<int> t(n+1),x(n+1),y(n+1);
    x[0]=y[0]=1; // start from (1,1)
    // t[0]=0
    for(int i=1;i<=n;i++) cin>>t[i]>>x[i]>>y[i];
    vector<int> dp(n+1,0),p_maxDP(n+1,0);
    for(int i=1;i<=n;i++){
        dp[i]=INT_MIN;
        for(int j=max(0,i-2*r);j<i;j++){
            if((t[i]-t[j])>=(abs(x[i]-x[j])+abs(y[i]-y[j]))){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        if(i>2*r) dp[i]=max(dp[i],1+p_maxDP[i-2*r]);
        p_maxDP[i]=max(p_maxDP[i-1],dp[i]);
    }
    cout<<p_maxDP[n]<<"\n";
    return 0;
}