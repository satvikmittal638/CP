#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    vector<int> c(n);
    for(auto &i:c) cin>>i;
    vector<long long> dp(x+1);
    dp[0]=1; // 1 way to make 0 rupees->take nothing
    
    for(int j=1;j<=x;j++){
        for(int i=0;i<n;i++){
        if(j-c[i]>=0)
            dp[j]+=dp[j-c[i]];
            dp[j]%=1000000007;
        }
    }
    cout<<dp[x];
    return 0;
}