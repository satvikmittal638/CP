#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
    const int INF=1e9;
fastio;
    int n,m;cin>>n>>m;
    vector<string> s(n);for(auto &i:s) cin>>i;
    /*
    dp[i][0] is minm cyclic distance of an alphabet
    dp[i][1] is minm cyclic distance of an digit
    dp[i][2] is minm cyclic distance of an special char
    for s[i]
    */
    vector<vector<int>> dp(n,vector<int>(3,INF));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(isalpha(s[i][j])){
                dp[i][0]=min(dp[i][0],min(j,m-j));
            }
            else if(isdigit(s[i][j])){
                dp[i][1]=min(dp[i][1],min(j,m-j));
            }
            else{
                dp[i][2]=min(dp[i][2],min(j,m-j));
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<3;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    int ans=INF;
    vector<int> p={0,1,2};
    do {
    vector<bool> used(n, 0); 
    int curAns = 0;

    for (int k = 0; k < 3; k++) {
        int minI = -1, min = INF;
        for (int i = 0; i < n; i++) {
            if (!used[i] && dp[i][p[k]] <= min) {
                min = dp[i][p[k]];
                minI = i;
            }
        }
        
        if (minI != -1) {  
            curAns += min;
            used[minI] = 1; 
        }
    }
    // cout<<curAns<<" ";
    ans = min(ans, curAns);

} while (next_permutation(all(p)));
    cout<<ans;
    return 0;
}