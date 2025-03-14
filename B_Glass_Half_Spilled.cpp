#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    const int INF=1e9;
    int N=104;
    int n;cin>>n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(N*N, -INF)));
    dp[0][0][0] = 0; // base case
    for(int i=1;i<=n;i++){
        for(int k=1;k<=i;k++){
            for(int A=0;A<N*N;A++){
                dp[i][k][A]=dp[i-1][k][A];
                if(A>=a[i]) dp[i][k][A]=max(dp[i][k][A],dp[i-1][k-1][A-a[i]]+b[i]);
            }
        }
    }
    cout<<fixed<<setprecision(9);
    float B=accumulate(all(b),0);
    for(int k=1;k<=n;k++){
        float ans;
        for(int A=1;A<=N*N;A++){
            ans=max(ans,min((float)A,((float)dp[n][k][A]+B)/2));
        }
        cout<<ans<<" ";
    }
    
    return 0;
}