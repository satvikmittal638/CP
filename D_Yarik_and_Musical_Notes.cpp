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
       map<pair<int,int>,ll> mp;
       for(int i=0;i<n;i++){
        int pow2=log2(a[i]);
        int num=a[i]-pow2,den=a[i]/(1<<(pow2));
        mp[{num,den}]++;
       }
       ll ans=0ll;
       for(auto &p:mp){
        int cnt=p.second;
        cout<<cnt<<" ";
        ans+=cnt*(cnt-1)/2;
       }
    //    cout<<ans<<"\n";
    }
    return 0;
}