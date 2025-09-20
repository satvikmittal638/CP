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
       vector<ll> sumlr(n);
       ll ans=0ll;
       for(int i=0;i<n;i++) cin>>sumlr[i];
       for(int i=0;i<n;i++){
        ll r;cin>>r;
        sumlr[i]+=r;
        ans+=r;
       }
       sort(all(sumlr)); 
       // pick lowest n/2 values
       for(int i=0;i<n/2;i++){
        ans-=sumlr[i];
       }
       // for odd n, check by removing each element
       if(n%2!=0){
        ans-=sumlr[0];
        ll finalAns=0ll;
        for(int i=0;i<n;i++){
            finalAns=max(finalAns,ans-sumlr[i]);
        }
        ans=finalAns;
       }
       cout<<ans<<'\n';

    }
    return 0;
}