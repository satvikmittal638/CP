#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll INF=1e18;
int main()
{
fastio;
    int n;cin>>n;
    string s;cin>>s;s=' '+s;
    vector<int> a(n+1);for(int i=1;i<=n;i++) cin>>a[i];
    // dp[i][j] denotes minm ambiguity for s[1,i] after deletion so that it becomes easy string of type j
    /*
    Type j:
    0)no h
    1)h
    2)ha
    3)har
    */
    vector<vector<ll>> dp(n+1,vector<ll>(4,INF));
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='h'){
            dp[i][0]=min(dp[i][0],dp[i-1][0]+a[i]);
            dp[i][1]=min({dp[i][1],dp[i-1][0],dp[i-1][1]});
            dp[i][2]=min(dp[i][2],dp[i-1][2]);
            dp[i][3]=min(dp[i][3],dp[i-1][3]);
        }
        else if(s[i]=='a'){
            dp[i][0]=min(dp[i][0],dp[i-1][0]);
            dp[i][1]=min(dp[i][1],dp[i-1][1]+a[i]);
            dp[i][2]=min({dp[i][2],dp[i-1][1],dp[i-1][2]});
            dp[i][3]=min(dp[i][3],dp[i-1][3]);
        }
        else if(s[i]=='r'){
            dp[i][0]=min(dp[i][0],dp[i-1][0]);
            dp[i][1]=min(dp[i][1],dp[i-1][1]);
            dp[i][2]=min(dp[i][2],dp[i-1][2]+a[i]);
            dp[i][3]=min({dp[i][3],dp[i-1][2],dp[i-1][3]});
        }
        else if (s[i]=='d'){
            dp[i][0]=min(dp[i][0],dp[i-1][0]);
            dp[i][1]=min(dp[i][1],dp[i-1][1]);
            dp[i][2]=min(dp[i][2],dp[i-1][2]);
            dp[i][3]=min(dp[i][3],dp[i-1][3]+a[i]);
        }
        else{
            dp[i][0]=min(dp[i][0],dp[i-1][0]);
            dp[i][1]=min(dp[i][1],dp[i-1][1]);
            dp[i][2]=min(dp[i][2],dp[i-1][2]);
            dp[i][3]=min(dp[i][3],dp[i-1][3]);
        }
    }
    
    cout<<*min_element(all(dp[n]));
    return 0;
}