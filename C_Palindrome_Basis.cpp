#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    //Pre-compute all palindromes(till all 5-digit palindromes)
    vector<int> palds;
    // 1-digit
    for(int a=1;a<=9;a++)
        palds.push_back(a);
    
    //2-digit
    for(int a=1;a<=9;a++)
        palds.push_back(11*a);
    
    // 3-digit
    for(int a=1;a<=9;a++)
        for(int b=0;b<=9;b++)
            palds.push_back(101*a+10*b);
    
    // 4 digit
    for(int a=1;a<=9;a++)
        for(int b=0;b<=9;b++)
            palds.push_back(1001*a+110*b);
    
    // 5-digit
    for(int a=1;a<=9;a++)
        for(int b=0;b<=9;b++)
            for(int c=0;c<=9;c++)
                palds.push_back(10001*a+1010*b+100*c);
    
    // precompute ways till 4X1e4
    const int MAX=4*1e4;
    const int MOD=1e9+7;
    vector<int> dp(MAX+1,0);
    // base-case
    dp[0]=1;
   for (auto p : palds) {
    for (int i = p; i <= MAX; i++) {
        dp[i] = (dp[i] + dp[i - p]) % MOD;
    }
    }
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       cout<<dp[n]<<"\n";
    }
    return 0;
}