#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int INF=100;
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n+1);
       a[0]=INF;
       for(int i=1;i<=n;i++) cin>>a[i];
       vector<queue<int>> start(n+1);
       vector<int> cnt(n+1,0),mx(n+1,0);
       //Greedy speedup mx[i] is maxm index j<=i s.t. cnt[a[i]] in [j,i] is exactly a[i]
       for(int i=1;i<=n;i++){
        start[a[i]].push(i);
        cnt[a[i]]++;
        if(cnt[a[i]]==a[i]){
            mx[i]=start[a[i]].front();
            start[a[i]].pop();
            cnt[a[i]]--;
        }
       }
    //    for(int i=1;i<=n;i++) cout<<mx[i]<<" ";
    //    cout<<'\n';
       // dp[i][0] is ans for [1,i] if a block ending at a[i] wasn't taken
       // dp[i][1] is ans for [1,i] if a block ending at a[i] was taken

       vector<vector<int>> dp(n+1,vector<int>(2,0));
    //    dp[0][0]=dp[0][1]=0;-> empty array
        for(int i=1;i<=n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1] = -INF;
            int j=mx[i];
            if(j>0){
                dp[i][1] = max(dp[j-1][0], dp[j-1][1]) + a[i];  
            }
        }
        // for(int i=0;i<=n;i++){
        //     cout<<dp[i][0]<<" ";
        // }
        // cout<<"\n";
        // for(int i=0;i<=n;i++){
        //     cout<<dp[i][1]<<" ";
        // }
        // cout<<"\n\n";
        cout<<max(dp[n][0],dp[n][1])<<"\n";

    }
    return 0;
}