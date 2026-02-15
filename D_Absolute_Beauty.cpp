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
      vector<ll> a(n),b(n);
      for(auto &i:a) cin>>i; 
      for(auto &i:b) cin>>i; 
      ll ans=0ll;
      for(int i=0;i<n;i++){
        if(a[i]>b[i]) swap(a[i],b[i]);
        ans+=b[i]-a[i];
      }
      // a[i]<=b[i] WLOG
      ll minb=*min_element(all(b)),mxa=*max_element(all(a));
      if(mxa>=minb) ans+=2*(mxa-minb);
      cout<<ans<<'\n';
    }
    return 0;
}