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
       ll n;cin>>n;
       vector<int> a(n);for(auto &i:a) cin>>i;
       int msb=log2(n);
       // counts no. of subarrs having xor value=x
       auto countSubarrs=[&](int x){
        ll ans=0ll;
        vector<ll> cnt((1<<(msb+1)),0ll);
        cnt[0]++;// empty prefix
        // map<int,ll> cnt;
        // cnt[0]=1; // empty prefix
        int cur=0;
        for(int i=0;i<n;i++){
            cur^=a[i];
            ans+=cnt[x^cur];
            cnt[cur]++;
        }
        return ans;
       };
       ll ans=n*(n+1)/2;
       for(int x=0;x*x<(1<<(msb+1));x++){
        ll cnt=countSubarrs(x*x);
        // if(cnt>0) cout<<x<<" "<<cnt<<"\n";
        ans-=cnt;
       }
       cout<<ans<<"\n";
    }
    return 0;
}