#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    const ll MOD=998244353;
    ll n,k;cin>>n>>k;
    vector<ll> p(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    ll val=n*k-k*(k-1)/2,cnt=1ll;
    for(int i=0;i<n;){
        if(p[i]>=n-k+1){
            i++;
            ll len=1ll;
            while(i<n && p[i]<n-k+1){
                i++;
                len++;
            }
            if(i<n){
                cnt*=len;
                cnt%=MOD;
            }
        }
        else{
            i++;
        }
    }
    cout<<val<<" "<<cnt;
    return 0;
}