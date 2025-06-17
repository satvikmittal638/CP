#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    ll tt;cin>>tt;
    while(tt--){
       ll n;cin>>n;
       vector<ll> a(n);for(auto &i:a) cin>>i;
       ll i=0;
       vector<ll> sub_len(n+1,0);
       while(i<n){
        ll curLen=1,num=a[i];
        while(i<n-1 && a[i+1]==a[i]){
            i++;
            curLen++;
        }
        sub_len[a[i]]=max(sub_len[a[i]],curLen);
        i++;
       }
    //    for(auto e:sub_len) cout<<e<<" ";
    //    cout<<"\n";
       ll ans=LLONG_MAX;
       for(ll i=1;i<=n;i++){
        if(sub_len[i]>0) ans=min(ans,i*(n-sub_len[i]));
        // cout<<ans<<" ";
       }
       cout<<ans<<"\n";
    }
    return 0;
}