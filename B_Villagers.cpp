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
       vector<ll> g(n+1,0);
       for(int i=1;i<=n;i++) cin>>g[i];
       sort(all(g));
       ll ans=LLONG_MAX;
       if(n%2==0){
        ans=0;
        for(int i=2;i<=n;i+=2) ans+=g[i];
       }
       else{
        vector<ll> p(n+5,0ll),s(n+5,0ll);
        for(int i=2;i<=n;i++){
            p[i]+=p[i-2]+g[i];
        }
        for(int i=n;i>=1;i-=2){
            s[i]=s[i+2]+g[i];
            s[i-1]=s[i];
        }

        // for(int i=1;i<=n;i++){
        //     cout<<p[i]<<" ";
        // }
        // cout<<'\n';
        // for(int i=1;i<=n;i++){
        //     cout<<s[i]<<" ";
        // }
        for(int i=1;i<=n;i+=2){
            ans=min(ans,p[i-1]+s[i+1]+g[i]);
        }
       }
       cout<<ans<<'\n';
    }
    return 0;
}