#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        vector<int> dp(n,0);
        // dp[0]=0; // no coins in the start
        int consecutiveThorns=0;
        for(int i=1;i<n;i++){
            if(s[i]!='*'){
                consecutiveThorns=0;//reset
                if(i>=2)
                    dp[i]=max(dp[i-1],dp[i-2]) + (s[i]=='@');
                else 
                    dp[i]=s[i]=='@';

            }
            else{
                consecutiveThorns++;
                if(consecutiveThorns>1){
                    break;
                }else{
                    dp[i]=dp[i-1];
                }
            }
        }
        cout<<*max_element(dp.begin(),dp.end())<<"\n";
    }
    return 0;
}