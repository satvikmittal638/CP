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
       vector<ll> suf(n);
       suf[n-1]=a[n-1];
       for(int i=n-2;i>=0;i--){
        suf[i]=suf[i+1]+a[i];
       }
       ll ans=suf[0];
       for(int i=1;i<n;i++){
        if(suf[i]>0) ans+=suf[i];
       }
       cout<<ans<<"\n";
    }
    return 0;
}