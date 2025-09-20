#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int MAX=4*1e5+10; // pref can have atmost 2A index
int main()
{
fastio;
int tt;cin>>tt;
while(tt--){
    ll n,y;cin>>n>>y;
    vector<ll> cnt(MAX,0ll);
    vector<int> pref(MAX,0ll);
    vector<ll> c(n);
    for(auto &i:c) {cin>>i;cnt[i]++;}
    partial_sum(all(cnt),pref.begin());
    ll A=*max_element(all(c));
    // edge case, x>1 gives price as 1 only
    if(A==1){
        cout<<n<<'\n';
        continue;
    }
    ll ans=LLONG_MIN;
    for(int x=2;x<=A;x++){
        ll cur=0ll;
        for(int p=1;p<=(A+x-1)/x;p++){
            ll need=pref[p*x]-pref[(p-1)*x];
            cur+=p*need-y*max(need-cnt[p],0ll);
        }
        ans=max(ans,cur);
    }
    cout<<ans<<'\n';
}
    return 0;
}