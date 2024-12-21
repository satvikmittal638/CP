#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n,m;cin>>n>>m;
    vector<int> type(n+1,0);
    vector<float> x(n+1,0);
    for(int i=1;i<=n;i++)
        cin>>type[i]>>x[i];
    /*
    dp[i][j] denotes the length of the longest increasing subsequence of [1,i]
    ending at type[j]
    */
   vector<vector<ll>> dp(n+1,vector<ll>(m+1));
   for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        
    }
   }

    return 0;
}