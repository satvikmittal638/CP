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
       int n,x;cin>>n>>x;
       vector<ll> a(n+1);
       for(int i=1;i<=n;i++)cin>>a[i];
       // compute prefix sum
        partial_sum(a.begin()+1,a.end(),a.begin()+1);
        /*
        dp[i] denotes the number of good subsegments starting from i
        */
        vector<int> dp(n+2);
        for(int i=n-1;i>=0;i--){
            // find the minm j s.t. pref[j]-pref[i-1]>x-->pref[j]>pref[i-1]+x
            int j=(upper_bound(all(a),a[i]+x)-a.begin())-1;
            dp[i]=dp[j+1]+(j-i);
        }
        cout<<accumulate(all(dp),0ll)<<"\n";
    }
    return 0;
}