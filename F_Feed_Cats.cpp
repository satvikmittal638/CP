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
        int n,m;cin>>n>>m;
        vector<int> ls;// seperate for BS
        vector<pair<int,int>> itvl(m);
        for(auto &i:itvl) cin>>i.first>>i.second;
        sort(all(itvl));
        for(auto [l,r]:itvl) ls.push_back(l);
        vector<int> cnt(n+2,0); // cnt[i] denotes no. of intervals containing point i
        for(auto [l,r]:itvl){
            cnt[l]++;
            cnt[r+1]--;
        }
        partial_sum(all(cnt),cnt.begin());

        vector<int> pmax(m);// pmax[i] is maxm of rs of itvl[0,i]
        pmax[0]=itvl[0].second;
        for(int i=1;i<m;i++){
            pmax[i]=max(pmax[i-1],itvl[i].second);
        }
        // find maxr
        vector<int> maxr(n+2,0);// maxr[i] is maxm r of all intervals point i is a part of
        for(int i=1;i<=n;i++){
            // find maxm l<=i
            auto it=upper_bound(all(ls),i);// first l>i
            if(it!=ls.begin()){
                it--;// last l<=i
                int pos=it-ls.begin();
                // check for valid interval
                if(pmax[pos]>=i) maxr[i]=pmax[pos];
            }
        }

        vector<int> dp(n+2,0),smax(n+2,0);
        // let dp[i] is maxm cats fed for [i,n] if i is the first chosen point
        // smax[i]=max(dp[i,n])
        // base:
        smax[n]=dp[n]=cnt[n];
        for(int i=n-1;i>=0;i--){
            // maxr[i]+1 may jump out of bounds to feed the last cat
            if(cnt[i]>0) dp[i]=cnt[i]+smax[maxr[i]+1];
            smax[i]=max(smax[i+1],dp[i]);
        }
        cout<<smax[0]<<'\n';
    }
    return 0;
}