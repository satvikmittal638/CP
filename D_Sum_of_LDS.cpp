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
       vector<int> p(n);for(auto &i:p) cin>>i;
       vector<ll> dp(n+2,0ll);// dp[i] is sum of length of LDSs for subarrays starting at i
       // base:dp[n]=dp[n+1]=0
       // observe:either of p[i] or p[i+1] is the suffix maxm of [i,n-1]
       for(int i=n-1;i>=0;i--){
        // p[i] is guaranteed to be start of LDS of any subarray starting at i
        if(p[i]>p[i+1]){
            dp[i]=dp[i+1]+n-i;
        }
        // p[i+1] is guaranteed to be start of LDS of any subarray starting at i+1
        // plus additional [i,i] interval has LDS=p[i] only
        else{
            dp[i]=dp[i+2]+n-i;
        }
       }
       cout<<accumulate(all(dp),0ll)<<"\n";
       
    }
    return 0;
}