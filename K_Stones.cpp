#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;cin>>n>>k;
    vector<int> a(n); for(auto &i:a) cin>>i;
    vector<bool> dp(k+1,0);
    // dp[0]=0;
    for(int i=1;i<=k;i++){
        for(auto e:a){
            /*
    If i≥j and it was not possible to win a game with i−e
stones, then - because the turns alternate - a game with 
i stones is winnable for taro
            */
            if(i>=e && !dp[i-e]) dp[i]=1;
        }
    }
    cout<<(dp[k]?"First":"Second");
    return 0;
}