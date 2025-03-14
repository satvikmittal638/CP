#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n,k;cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    auto isSafe=[&](ll x){
        // dp[i] denotes the maxm number of unchanged elements on a prefix of length i 
        //whilst keeping a[i] unchanged
        vector<int> dp(n+1,0);
        int mxUnchanged=INT_MIN;
        for(int i=1;i<=n;i++){
            dp[i]=1; // base case(by construction)
            // ! Can't greedily select the nearest j
            for(int j=1;j<i;j++){
                if(abs(a[i]-a[j])<=(i-j)*x){
                    dp[i]=max(dp[i],dp[j]+1);
                }
                mxUnchanged=max(mxUnchanged,dp[i]);
            }
        }
        return (n-mxUnchanged)<=k;
    };

    // BS on minm value of max(c(a))
    ll lo=0,hi=2*1e9,ans;
    while(lo<=hi){
        int mid=(lo+hi+1)/2;
        if(isSafe(mid)){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    cout<<ans;
    return 0;
}