#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<ll> b(n);for(auto &i:b) cin>>i;
       vector<ll> p_max(n,0ll),s_max(n,0ll);
       p_max[0]=b[0];
       for(int i=1;i<n;i++){
        p_max[i]=max(p_max[i-1],b[i]+i);
       }
       s_max[n-1]=b[n-1]-(n-1);
       for(int i=n-2;i>=0;i--){
        s_max[i]=max(s_max[i+1],b[i]-i);
       }
       ll ans=0ll;
       // brute all values of i2
       for(int i=1;i<n-1;i++){
        ans=max(ans,p_max[i-1]+b[i]+s_max[i+1]);
       }
       cout<<ans<<"\n";
    }
    return 0;
}