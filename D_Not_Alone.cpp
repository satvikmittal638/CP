#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll INF=1e18;
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<ll> a(n+1,0);
       for(int i=1;i<=n;i++) cin>>a[i];
       auto cost=[](vector<ll> x){
        sort(all(x));
        return x.back()-x.front();
       };
       auto solve=[&](){
        // dp[i] is minm cost for a[1,i]
        // we need blocks of equal values of length either 2 or 3
        vector<ll> dp(n+1,INF);
        dp[0]=0;
        // dp[1] is invalid state
        dp[2]=cost({a[1],a[2]});
        dp[3]=cost({a[1],a[2],a[3]});
        for(int i=4;i<=n;i++){
            dp[i]=min(dp[i-2]+cost({a[i-1],a[i]}),dp[i-3]+cost({a[i-2],a[i-1],a[i]}));
        }
        // cyclically shift 'a' for next turn
        rotate(a.begin() + 1, a.begin() + 2, a.end());
        return dp[n];
       };
       // atmost 2 cyclic shifts needed
       cout<<min({solve(),solve(),solve()})<<'\n';
       
    }
    return 0;
}