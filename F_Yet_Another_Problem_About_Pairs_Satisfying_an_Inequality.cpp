#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       // dp[i] stores no. of elts from 1..i which satisfy a[i]<i
       vector<ll> a(n+1),dp(n+1,0ll);
       for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i]=dp[i-1]+(a[i]<i);
       }
       ll ans=0ll;
       for(int i=2;i<=n;i++){
        if(a[i]<i && 1<=a[i]-1 && a[i]-1<=n) ans+=dp[a[i]-1];
       }
       cout<<ans<<"\n";
    }
    return 0;
}