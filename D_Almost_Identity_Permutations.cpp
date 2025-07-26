#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    ll n,k1;cin>>n>>k1;
    vector<ll> D={0,0,1,2,9};
    ll ans=1ll; // identity perm
    for(int k=1;k<=k1;k++){
        if(k==4){
            ans+=D[k]*n*(n-1)*(n-2)*(n-3)/24;
        }
        else if(k==3){
            ans+=D[k]*n*(n-1)*(n-2)/6;
        }
        else if(k==2){
            ans+=D[k]*n*(n-1)/2;
        }
        else{
            ans+=D[k]*n;
        }
    }
    cout<<ans;
    return 0;
}