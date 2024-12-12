#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;cin>>n>>m;
    vector<string> grid(n);
    for(auto &i:grid) cin>>i;
    vector<vector<long long>> dp(n,vector<long long>(m,0));
    dp[0][0]=(grid[0][0]=='0');
    // fill row wise
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='0'){
                // if conditionals to handle first row and first col
                if(i>=1) {
                    int k=i-1;
                    // search for nearest unblocked cell in same column
                    while(k>=0 && grid[k][j]=='1'){
                        k--;
                    }
                    if(k>=0){
                        dp[i][j]+=dp[k][j];
                    }
                }
                if(j>=1) {
                    int k=j-1;
                    // search for nearest unblocked cell in same row
                    while(k>=0 && grid[i][k]=='1'){
                        k--;
                    }
                    if(k>=0){
                        dp[i][j]+=dp[i][k];
                    }
                }
                dp[i][j]%=1000000007;
            }
        }
    }
    cout<<dp[n-1][m-1];
    // for(auto v:dp){
    //     for(auto e:v){
    //         cout<<e<<" ";
    //     }
    //     cout<<"\n";
    // }
    return 0;
}