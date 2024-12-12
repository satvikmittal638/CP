#include<iostream>
#include<vector>
using namespace std;
int main()
{
    long long n;cin>>n;
    vector<int> c={1,5,10,20,100};
    vector<long long> dp(n+1,LLONG_MAX);
    dp[0]=0;
    for(int coin:c){
        for(int i=1;i<=n;i++){
            if(i-coin>=0)
            dp[i]=min(dp[i],dp[i-coin]+1);
        }
    }
    cout<<dp[n];
    return 0;
}