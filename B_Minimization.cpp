#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n,k;cin>>n>>k;
    if(k>=n) {
        cout<<0;
        return 0;
    }
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    // greedily its best to take contiguos segments of sorted array as a chain of elts
    sort(a.begin()+1,a.end());
    int s1=n/k,s2=s1+1; // 2 sizes of chain are possible, floor(n/k) and roof(n/k)
    // dp[i][j] denotes the the sum value on a prefix of size i.s1+j.s2
    //i.e. i segments of size s1, j segments of size s2
    vector<vector<int>> dp(k+1,vector<int>(k+1,INT_MAX));
    dp[0][0]=0;
    for(int i=0;i<=k;i++){
        for(int j=0;j<=k;j++){
            int start1=(i-1)*s1+j*s2+1,start2=i*s1+(j-1)*s2+1;
            if(i>0 && start1+s1-1<=n) dp[i][j]=min(dp[i][j],dp[i-1][j]+a[start1+s1-1]-a[start1]);
            if(j>0 && start2+s2-1<=n) dp[i][j]=min(dp[i][j],dp[i][j-1]+a[start2+s2-1]-a[start2]);
        }
    }
    int cnt2=n%k,cnt1=k-cnt2;
    cout<<dp[cnt1][cnt2];
    return 0;
}