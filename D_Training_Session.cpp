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
       ll n;cin>>n;
       vector<ll> cntT(n+1,0ll),cntD(n+1,0ll),a(n),b(n);
       for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        cntT[a[i]]++;cntD[b[i]]++;
       }
       ll ans=n*(n-1)*(n-2)/6;
       for(int i=0;i<n;i++){
        ans-=(cntT[a[i]]-1)*(cntD[b[i]]-1);
       }
       cout<<ans<<"\n";
    }
    return 0;
}