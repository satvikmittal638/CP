#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n;cin>>n;
    vector<ll> a(n);for(auto &i:a) cin>>i;
    ll cur=0ll,mnS=0ll,ans=LLONG_MIN;
    for(int i=0;i<n-1;i++){
        if(i%2==0) cur+=abs(a[i]-a[i+1]);
        else cur-=abs(a[i]-a[i+1]);
        ans=max(ans,cur-mnS);
        mnS=min(mnS,cur);
    }
    cout<<ans;
    return 0;
}