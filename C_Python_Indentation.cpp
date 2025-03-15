#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

int main()
{
fastio;
    const ll MOD=1e9+7;
    int n;cin>>n;
    vector<char> cmd(n);for(auto &i:cmd) cin>>i;
    // for a base case
    cmd.insert(cmd.begin(),'s');
    n++;
    // both lines and indentations are 0-indexed
    vector<ll> prev_dp(n,0),cur_dp(n,0),prev_p(n,1),cur_p(n,0);
    
    // base case
    prev_dp[0]=1;

    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(cmd[i-1]=='f')
                cur_dp[j]=(j>0?prev_dp[j-1]:0);
            
            else
                cur_dp[j] = (prev_p[n-1] - (j>0 ? prev_p[j-1] : 0) + MOD) % MOD;            
            
            cur_p[j]=cur_dp[j];
            if(j>0) cur_p[j]+=cur_p[j-1];
            cur_dp[j]%=MOD;
            cur_p[j]%=MOD;
        }
        // roll the DP
        prev_dp=cur_dp;
        prev_p=cur_p;
    }
    cout<<cur_p[n-1];
    return 0;
}