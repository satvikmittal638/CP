#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()


int main()
{
fastio;
    vector<ll> pow10={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
    ll tt;cin>>tt;
    while(tt--){
       ll n,k;cin>>n>>k;
       k++;
       vector<ll> a(n);for(auto &i:a) cin>>i;
       auto f=[&](ll s){
        ll ans=0ll;
        for(ll i=n-1;i>=0;i--){
            ans+=s/pow10[a[i]];
            s%=pow10[a[i]];
        }
        return ans;
       };
       ll s=0ll;
       // greedily build the solution
       for(int i=0;i<n;i++){
        ll take=k;
        if(i<n-1) take=min(take,pow10[a[i+1]]/pow10[a[i]]-1);
        s+=pow10[a[i]]*take;
        k-=take;
       }
       cout<<s<<"\n";
    }
    return 0;
}