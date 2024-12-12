#include<iostream>
#include<vector>
using namespace std;
int main()
{
    const long long MOD=1e9+7,MAX=2000;
    int t;cin>>t;
    // pre-processing
    // dp[i] denotes the no of towers with height i
    vector<long long> dp(MAX+1);
    dp[0]=1;
    dp[1]=2;
    for(int i=2;i<=MAX;i++){
        for(int j=1;j<i;j++){
            dp[i]+=(dp[j]*dp[i-j])%MOD;
            dp[i]%=MOD;
        }
    }
    // while(t--){
    //     int n;cin>>n;
    //     cout<<dp[n]<<"\n";
    // }
    cout<<dp[2];
    return 0;
}