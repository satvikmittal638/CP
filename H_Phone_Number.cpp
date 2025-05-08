#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    string s;cin>>s;
    int n=s.length();
    s=' '+s;
    vector<vector<ll>> dp(55,vector<ll>(12,0));
    // base case(can choose any digit as 1st one)
    for(int j=0;j<=9;j++){
        dp[1][j]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<=9;j++){
        int d=s[i]-'0';
            dp[i][(d+j)/2]+=dp[i-1][j];
            // to prevent updating same DP twice
            if((d+j)%2!=0){
                dp[i][(d+j+1)/2]+=dp[i-1][j];
            }
        }
    }
    ll ans=accumulate(all(dp[n]),0ll);
    /*
    
    Masha can obtain her own number iff the consective digits differ by atmost 1
    this will happen when she chooses the first digit same as her no.
    and only takes floor values at each step
    */

    int sub=1;
    for(int i=2;i<=n;i++){
        if(s[i]-s[i-1]>1){
            sub=0;break;
        }
    }
    ans-=sub;
    cout<<ans;
    return 0;
}