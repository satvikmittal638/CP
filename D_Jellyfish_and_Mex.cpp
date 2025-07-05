#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    ll inf=1e18;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<ll> cnt(5002);
       for(int i=0;i<n;i++){
           ll a;cin>>a;
           if(a<=5000) cnt[a]++;
        }
    // calculate mex of original array
        ll mex=0ll;
        while (cnt[mex]) mex++;
       vector<ll> dp(mex+1,inf);
    // base case: m is 0 when mex(a)=mex
       dp[mex]=0;
       for(ll i=mex;i>=0;i--){
        for(ll j=0;j<i;j++){
            // transition the MEX from i to j(i.e. decrease it)
            if(cnt[j]==0) continue;
            dp[j]=min(dp[j],dp[i]+i*(cnt[j]-1)+j);
        }
       }
       cout<<(dp[0])<<"\n";// final mex=0
    }
    return 0;
}