#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll MOD=1e9+7;
int n;
vector<int> a;

int dp[1001];
ll cnt[1001]; // # of LIS ending at a[i]
// |LIS| ending at a[i]
int rec(int i){
    if(i < 0) return 0;
    if(dp[i] != -1) return dp[i];

    int mx = 0;
    for(int j = 0; j < i; j++){
        if(a[j] < a[i]){
            mx = max(mx, rec(j));
        }
    }

    if(mx == 0) cnt[i] = 1;

    for(int j = 0; j < i; j++){
        if(a[j] < a[i] && rec(j) == mx){
            cnt[i] += cnt[j];
            cnt[i]%=MOD;
        }
    }

    return dp[i] = mx + 1;
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       cin>>n;a.assign(n,0);
       for(auto &i:a) cin>>i;
       memset(dp,-1,sizeof(dp));
       memset(cnt,0,sizeof(cnt));
       int lis=0;
       for(int i=0;i<n;i++){
        lis=max(lis,rec(i));
       }
       // now all endings with give |LIS|=lis are valid endings of reqd LISs
       ll ans=0ll;
       for(int i=0;i<n;i++){
        if(rec(i)==lis) ans+=cnt[i];
        ans%=MOD;
       }
       cout<<ans<<'\n';
    }
    return 0;
}