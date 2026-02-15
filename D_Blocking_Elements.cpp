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
       vector<ll> a(n+1,0);
       for(int i=1;i<=n;i++)cin>>a[i];
       // make suffix sum to account for last subarray
        vector<ll> suf(n+2,0);
        for(int i=n;i>=1;i--) suf[i]=suf[i+1]+a[i];
       // checks if ans<=x
       auto isSafe=[&](ll x){
        // dp[i] be the minm blocked sum with a[i] blocked last after processing b[0,i] 
        vector<ll> dp(n+1,0); // base:dp[0]=0-> no elt blocked
        multiset<ll> msdp;// to speedup finding minm val of dp
        msdp.insert(dp[0]);
        ll cur=0ll;
        int lastj=0; // start at empty subarray
        for(int i=1;i<=n;i++){
            // if sum of window exceeds, start removing elts from start of the window
            while(lastj<=n && msdp.size() && cur>x){
                msdp.erase(msdp.find(dp[lastj]));
                cur-=a[lastj+1];
                lastj++;
            }
            // dp[i]=min(dp[j]) over all 1<=j<i s.t. sum(a[j+1,i-1])<=m
            dp[i]=*msdp.begin() + a[i];
            // update for next dp
            cur+=a[i];
            msdp.insert(dp[i]);
        }
        ll minBlocked=LLONG_MAX;
        // let the last blocked elt be a[i]
        for(int i=0;i<=n;i++){
            // check for last subarray
            if(suf[i+1]<=x) minBlocked=min(minBlocked,dp[i]);
        }
        return minBlocked<=x;
       };
       // b.s. for ans
       ll lo=0,hi=suf[1];
       // issue fixed: if tracking ans, use lo<=hi
       // if not, use lo<hi
       while(lo<hi){
        ll mid=(lo+hi)/2;
        // try to minimize the ans
        if(isSafe(mid)){
            hi=mid;// keep ans in range
        }
        else{
            lo=mid+1;
        }
       }
       cout<<lo<<'\n';

    }
    return 0;
}