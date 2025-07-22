#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    ll n,m;cin>>n>>m;
    vector<int> a(n);for(auto &i:a) cin>>i;
    // calculates no. of subarrays for a given length x
    auto f=[](ll x){
        return x*(x+1)/2;
    };
    // returns contribution of a join
    auto calc=[&](ll i){
        return f(n)-f(i+1)-f(n-i-1);
    };
    ll ans=f(n);
    for(ll i=0;i<n-1;i++){
        if(a[i]!=a[i+1]){
            ans+=calc(i);
        }
    }
    while(m--){
        ll i,x;cin>>i>>x;i--;
        // remove both joints
        if(i>0) ans-=(a[i-1]!=a[i])*calc(i-1);
        if(i<n-1) ans-=(a[i+1]!=a[i])*calc(i);
        a[i]=x;
        // add joints
        if(i>0) ans+=(a[i-1]!=a[i])*calc(i-1);
        if(i<n-1) ans+=(a[i+1]!=a[i])*calc(i);
        cout<<ans<<"\n";
    }

    return 0;
}