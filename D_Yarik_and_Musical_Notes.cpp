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
       vector<int> a(n);for(auto &i:a) cin>>i;
       ll cnt1=0ll,cnt2=0ll;
       map<int,ll> cnt;
       ll ans=0ll;
       for(int i=0;i<n;i++){
        ans += cnt[a[i]];
		if (a[i] == 1) ans += cnt[2];
		else if (a[i] == 2) ans += cnt[1];
		cnt[a[i]]++;
       }
       cout<<ans<<"\n";
    }
    return 0;
}