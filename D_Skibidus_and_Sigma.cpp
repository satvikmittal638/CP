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
       ll n,m;cin>>n>>m;
       vector<vector<ll>> a(n,vector<ll>(m));
       vector<ll> sum;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
       }
       sort(all(a),[](auto v1,auto v2){
        return accumulate(all(v1),0ll)>accumulate(all(v2),0ll);
       });
       // now take largest array first in the sum
       ll ans=0ll,pref=0ll;;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            pref+=a[i][j];
            ans+=pref;
        }
       }
       cout<<ans<<"\n";
    }
    return 0;
}