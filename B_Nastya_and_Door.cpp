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
       vector<int> a(n),dp(n,0);for(auto &i:a) cin>>i;
       // dp[i] denotes number of peaks in prefix [1,i]
       for(int i=1;i<n-1;i++){
        dp[i]=dp[i-1]+(a[i-1]<a[i] && a[i]>a[i+1]);
       }
       int mxPeaks=0,minL=n;
       for(int l=0;l<=n-k;l++){
        int r=l+k-1;
        int curPeaks=dp[r-1]-dp[l];
        mxPeaks=max(mxPeaks,curPeaks);
       }
        for(int l=0;l<=n-k;l++){
        int r=l+k-1;
        int curPeaks=dp[r-1]-dp[l];
        if(curPeaks==mxPeaks){
            minL=l;break;
        }
       }

       cout<<mxPeaks+1<<" "<<minL+1<<"\n";
    }
    return 0;
}