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
       int n,k;cin>>n>>k;
       //dp[l] is idx i s.t. 0<=i<=l s.t. (l-i+1)a[i] is maxm, i.e. a[i] remains as prefix maxm in [i,l] giving maxm cost
       vector<int> a(n),dp(n);for(auto &i:a) cin>>i;
       //0<=i<=l
       auto exp=[&](int l,int i){
        return (l-i+1)*a[i];
       };
       dp[0]=0;// base
       for(int l=n-1;l>0;l--){
        // considering pref_max doesn't change, considering pref_max changes at index l
        int e1=exp(l,dp[l-1]),e2=exp(l,l);
        // profit increases
        if(e2>e1){
            dp[l]=l;
        }
        else{
            dp[l]=dp[l-1];
        }
       }
       for(auto e:dp) cout<<e<<' ';
       int i=n-1;
       ll ans=0ll;
       while(i>=0){
        ans+=exp(i,dp[i]);
        i=dp[i]-1;
       }
    //    cout<<ans<<'\n';
    }
    return 0;
}