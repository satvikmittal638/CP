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
       map<int,int> cnt_prefs;
       int sum=0;
       cnt_prefs[sum]++;
       for(int i=1;i<=n;i++){
        char c;cin>>c;
        sum+=c-'0';
        cnt_prefs[sum-i]++;
       }
       ll ans=0ll;
       for(auto &p:cnt_prefs){
        ll cnt=p.second;
        ans+=cnt*(cnt-1)/2;
       }
       cout<<ans<<"\n";

    }
    return 0;
}