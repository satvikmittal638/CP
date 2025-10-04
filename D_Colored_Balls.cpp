#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll MOD=998244353;
int main()
{
fastio;
    ll n;cin>>n;
    vector<ll> a(n);for(auto &i:a) cin>>i;
    // sort(all(a));
    // dp[s] is the no. of subsets with sum=s
    vector<ll> dp(5001,0ll);
    dp[0]=1; // 1 empty subset
    ll ans=0ll;
    for(ll i=0;i<n;i++){
        /*
        a backward loop guarantees that when we compute dp[s + a[i]], we are using dp[s] from the previous stage (before a_i was considered). this correctly models adding a[i] just once.
        */
        for(ll s=5000-a[i];s>=0;s--){
            ans+=dp[s]*max(a[i],(s+a[i]+1)/2);// a[i] is the maxm of the subset(due to sorted a)
            ans%=MOD;
            dp[s+a[i]]+=dp[s];
            dp[s+a[i]]%=MOD;
        }
    }
    cout<<ans;
    return 0;
}