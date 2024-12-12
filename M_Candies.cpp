#include<bits/stdc++.h>
using namespace std;
int main()
{
    const long long MOD=1000000007;
    int n,k;cin>>n>>k;
    vector<long long> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    /*
    dp[i][j] denotes number of ways for first i children to
    distribute a total of j candies amongst themselves
    dp[i][j]=summation(0<=l<=ai) dp[i-1][j-l]
    let dp[i][j]==cur_row[j] 
    let dp[i-1][j]==prev_row[j] 
    */
   // i starts at 1
   
   vector<long long> cur_row(k+1),prev_row(k+1,0);
    prev_row[0]=1;
    
    
    return 0;
}