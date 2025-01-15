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
       vector<int> h(n);for(auto &i:h) cin>>i;
       int maxCoolness=(n-1)/2;
    ll ans=0;
        if(n%2!=0){
            ll tilesReq=0ll;
            for(int i=1;i<n;i+=2){
                if(h[i]<=max(h[i-1],h[i+1]))
                tilesReq+=max(h[i-1],h[i+1])-h[i]+1;
            }
            ans=tilesReq;
        }
        else{
            int curCoolness=0;
            for(int i=1;i<n-1;i++){
                if(h[i]>max(h[i-1],h[i+1])) curCoolness++;
            }
            if(curCoolness<maxCoolness){
                ll tilesReq1=0ll,tilesReq2=0ll;
                for(int i=1;i<n-1;i+=2){
                    if(h[i]<=max(h[i-1],h[i+1]))
                    tilesReq1+=max(h[i-1],h[i+1])-h[i]+1;
                }
                for(int i=2;i<n;i+=2){
                    if(h[i]<=max(h[i-1],h[i+1]))
                    tilesReq2+=max(h[i-1],h[i+1])-h[i]+1;
                }
                // cout<<tilesReq1<<" "<<tilesReq2<<" ";
                ans=min(tilesReq1,tilesReq2);
            }
        }
        cout<<ans<<"\n";


      
    }
    return 0;
}