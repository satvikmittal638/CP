#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
vector<double> dp(1e6+1,0ll);
double sum=0;
for(int i=1;i<=1e6;i++){
    dp[i]=1+sum/i;
    sum+=dp[i];
}
// for(int i=1;i<=10;i++) cout<<dp[i]<<" ";
    int tt;cin>>tt;
    while(tt--){
       ll n;cin>>n;
       cout<<(ll)dp[n]<<'\n';
    }
    return 0;
}