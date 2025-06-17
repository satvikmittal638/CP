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
       vector<ll> p(2*n);for(auto &i:p) cin>>i;
       ll ans=LLONG_MAX;
       if(n==1){
        ans=abs(p[0]-p[1]);
       }
        else if(n==2){
            ans=0ll;
            for(auto e:p){
                ans+=abs(e-2);
        }
       }
       ll cur=0ll;
       for(auto e:p) cur+=abs(e);
       ans=min(ans,cur);
       if(n%2==0){
        cur=0ll;
        for(auto e:p) cur+=abs(e+1);
        for(auto e:p){
            ans=min(ans,cur-abs(e+1)+abs(e-n));
        }
       }
       cout<<ans<<"\n";
    }
    return 0;
}