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
       vector<ll> a(n),pref(n);for(auto &i:a) cin>>i;
       pref[0]=a[0];
       for(int i=1;i<n;i++) pref[i]=pref[i-1]+a[i];
       ll ans=0ll;
       int i=0;
       // skip to the 1st 0
       while(i<n && a[i]!=0) {
        ans+=(pref[i]==0);
        i++;
       }
       for(;i<n;){
        map<ll,ll> cnt;
        cnt[pref[i]]++;
        i++; // 0_
        while(i<n && a[i]!=0){
            cnt[pref[i]]++;
            i++;
        }
        ll mxF=0ll;
        // find maximum frequency of any sum
        for(auto &[sum,f]:cnt){
            mxF=max(mxF,f);
        }
        ans+=mxF;
        // cout<<ans<<" ";
       }
       cout<<ans<<"\n";

    }
    return 0;
}