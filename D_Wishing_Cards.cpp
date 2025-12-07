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
       vector<int> a(n+1);
       for(int i=1;i<=n;i++) cin>>a[i];
       // compress the array based on prefix max
       map<ll,ll> mp;
       int p_max=0ll;
       for(int i=1;i<=n;i++){
        p_max=max(p_max,a[i]);
        mp[p_max]++;
       }
       vector<ll> comp_a,cnt;
       for(auto &[k,v]:mp){
        comp_a.push_back(k);
        cnt.push_back(v);
       }
       // let dp[s][m] is maxm happines for friends we have processed so far
        vector<vector<ll>> dp(k+1,vector<ll>(k+1,-1));
        dp[0][0]=0;// base case
        // O(k^4)
       for(int i=0;i<comp_a.size();i++){
        int cap=comp_a[i],len=cnt[i];
        vector<vector<ll>> nxt_dp(k+1,vector<ll>(k+1,-1));// temp dp for rolling
        for(int s=0;s<=k;s++){
            for(int m=0;m<=k;m++){
                if(dp[s][m]==-1) continue;
                // maintain maxm at m
                nxt_dp[s][m]=max(nxt_dp[s][m],dp[s][m]+m*len);

                // try to increase the maximum to j(>m)
                for(int j=m+1;j<=cap;j++){
                    if(s+j>k) break;
                    nxt_dp[s+j][j]=max(nxt_dp[s+j][j],dp[s][m]+j*len);
                }
            }
        }
        dp=nxt_dp;
       }
       ll ans=0ll;
       for(int s=0;s<=k;s++){
        for(int m=0;m<=k;m++){
            ans=max(ans,dp[s][m]);
        }
       }
       cout<<ans<<'\n';
    }
    return 0;
}