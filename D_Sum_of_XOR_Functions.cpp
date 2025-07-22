#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
ll MOD=998244353;
fastio;
    int n;cin>>n;
    vector<ll> a(n);for(auto &i:a) cin>>i;
    ll ans=0ll;
    for(ll b=0;b<31;b++){
        vector<pair<ll,ll>> cnt_pref(2);//cnt,sum of indices
        cnt_pref[0].first++;cnt_pref[0].second=-1;//empty prefix
        int cur=0;
        ll cur_ans=0ll;
        for(ll i=0;i<n;i++){
            int bit=((1<<b)&a[i])!=0;// 0 or 1
            cur^=bit;
            auto &[sz,sum]=cnt_pref[cur^1];// reqd target prefix has xor=cur^1
            cur_ans+=i*sz-sum;
            cur_ans%=MOD;
            // update for current prefix
            cnt_pref[cur].first++;cnt_pref[cur].second+=i;
        }
        // cout<<cur_ans<<" ";
        ans+=(1ll<<b)*cur_ans;
        ans%=MOD;
    }
    cout<<ans;
    return 0;
}