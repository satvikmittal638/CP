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
        int n,k;cin>>n>>k;
        vector<int> a(n);
        map<ll,ll> cntMod;
        for(int i=0;i<n;i++){
            cin>>a[i];
            a[i]=(k-(a[i]%k))%k;
            if(a[i]!=0) cntMod[a[i]]++;
        }
        ll ans=0ll;
        for(auto &[mod,cnt]:cntMod){
            ans=max(ans,mod+(cnt-1)*k);
        }
        ans+=ans!=0;
        cout<<ans<<"\n";
    }
    return 0;
}