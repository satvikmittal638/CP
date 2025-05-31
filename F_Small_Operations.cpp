#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    // precompute divisors of all numbers upto 1e6
    int MAX=1e6+5;
    vector<vector<int>> divs(MAX,vector<int>());
    // O(MAX)
    for(int i=1;i<=MAX;i++){
        //mark out i as a factor of its multiples
        // O(log(MAX))
        for(int j=i;j<=MAX;j+=i){
            divs[j].push_back(i);
        }
    }
    int tt;cin>>tt;
    while(tt--){
       int x,y,k;cin>>x>>y>>k;
       // computes minm no. of factors <=k into which 'a' can be decomposed into
       auto cnt_min_fact_less_k=[&](int a){
        vector<int> dp(a+5,INT_MAX);
        dp[1]=0;
        for(auto i:divs[a]){
            for(auto j:divs[i]){
                if(i/j <=k){
                    dp[i]=min(dp[j]+1,dp[i]);
                }
            }
        }
        return dp[a];
       };
       int h=gcd(x,y);
       int cntx=cnt_min_fact_less_k(x/h),cnty=cnt_min_fact_less_k(y/h);
       int ans;
       if(cntx>=0 && cnty>=0) ans=cntx+cnty;
       else ans=-1;
       cout<<ans<<"\n";
    }
    return 0;
}