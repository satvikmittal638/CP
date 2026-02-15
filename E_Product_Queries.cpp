#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

#ifndef ONLINE_JUDGE
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
#else
#define error(args...)
#endif
const ll INF=1e18;
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<ll> dp(n+1,INF);
       for(int i=0;i<n;i++){
        ll a;cin>>a;
        dp[a]=1;
       }
       for(int i=1;i<=n;i++){
        for(int j=1;j*j<=i;j++){
            if(dp[j]>=INF) continue;
            if(i%j==0){
                dp[i]=min(dp[i],dp[i/j]+dp[j]);
            }
        }
       }
       for(int i=1;i<=n;i++) {
        if(dp[i]>=INF) dp[i]=-1;
        cout<<dp[i]<<' ';
       }
       cout<<'\n';
    }
    return 0;
}