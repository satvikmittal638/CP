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
       int n,m,k,d;cin>>n>>m>>k>>d;
       vector<ll> a(n+1);// a[i] is the minm cost to build supports for row i
       for(int i=1;i<=n;i++){
        ll x;
        vector<ll> dp(m+1,0ll);// dp[j] is the minm cost to build supports on [1,j] s.t. there are supports at 1 and j
        multiset<ll> ms;
        cin>>x;x++;
        dp[1]=x;
        ms.insert(dp[1]); // base case
        for(int j=2;j<=m;j++){
            cin>>x;x++; // x is now the cost instead of the depth
            dp[j]=*ms.begin()+x;
            ms.insert(dp[j]);
            int outOfWin=j-(d+1);
            if(outOfWin>=1) {
                ms.erase(ms.find(dp[outOfWin]));
            }
        }
        a[i]=dp[m];
       }
    //    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    //    cout<<"\n";

       // find minm sum over all subarrays of size k
       ll sum = 0, ans = LLONG_MAX;
       for (int i = 1; i <= n; i++) {
           sum += a[i];
           if (i > k) sum -= a[i - k];// remove from window
           if (i >= k) ans = min(ans, sum);// update the ans
       }
       cout <<ans << "\n";

    }
    return 0;
}