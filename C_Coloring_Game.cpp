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
       vector<int> a(n);for(auto &i:a) cin>>i;
       sort(all(a));
       int mx=a[n-1];
       ll ans=0ll;
       for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            // find first c>mx-a-b
            auto itLo=upper_bound(a.begin()+j+1,a.end(),mx-a[i]-a[j]);
            if(itLo==a.end()) continue;

            // find first c>=a+b
            auto itHi=lower_bound(itLo,a.end(),a[i]+a[j]);
            if (itHi == itLo) continue; // No element in range
            itHi--; // find last c<a+b
            ans+=(itHi-itLo+1); // find all c E (mx-a-b,a+b)
        }
       }
       cout<<ans<<'\n';
    }
    return 0;
}