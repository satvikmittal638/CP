#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll MOD=1e9+7;
int main()
{
fastio;
    ll tt;cin>>tt;
    while(tt--){
       ll n;cin>>n;
       vector<ll> a(n+1,0);
       for(ll i=1;i<=n;i++) cin>>a[i];
       vector<vector<vector<ll>>> ways(n+1,vector<vector<ll>>(n+1,vector<ll>(n+1,0)));
       // base case(only empty subsequences can be formed)
       ways[0][0][0]=1;
       // iterate over the source states(the prvsly calculated states) and push the changes to the destination state
       for(ll i=0;i<n;i++){
        for(ll m=0;m<=n;m++){
            for(ll mp=0;mp<=n;mp++){
                ways[i+1][m][mp]+=ways[i][m][mp]; // don't use a[i]
                
                // use a[i]
                if(a[i+1]>=m) ways[i+1][a[i+1]][mp]+=ways[i][m][mp];
                else if(mp<=a[i+1] && a[i+1]<m) ways[i+1][m][a[i+1]]+=ways[i][m][mp];
                // no valid transition for a[i]<mp<m -> it forms an LDS of length=3
                ways[i+1][m][mp]%=MOD;
                ways[i+1][a[i+1]][mp]%=MOD;
                ways[i+1][m][a[i+1]]%=MOD;
            }
        }
       }
       ll ans=0ll;
       for(ll m=0;m<=n;m++){
        for(ll mp=0;mp<=n;mp++){
            ans=(ans+ways[n][m][mp])%MOD;
        }
       }
       cout<<ans<<'\n';
       
    }
    return 0;
}