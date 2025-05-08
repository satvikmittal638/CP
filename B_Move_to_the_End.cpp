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
       vector<ll> a(n);for(auto &i:a) cin>>i;
       vector<ll> s_sum(n),p_max(n);
       s_sum[n-1]=a[n-1];
       for(int i=n-2;i>=0;i--){
        s_sum[i]=s_sum[i+1]+a[i];
       }
       p_max[0]=a[0];
       for(int i=1;i<n;i++){
        p_max[i]=max(p_max[i-1],a[i]);
       }
       for(int k=n-1;k>=0;k--){
        ll ans=s_sum[k];
        if(k>0) ans=max(ans,ans+p_max[k-1]-a[k]);
        cout<<ans<<" ";
       }
       cout<<"\n";
    }
    return 0;
}