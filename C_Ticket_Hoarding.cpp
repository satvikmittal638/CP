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
       ll n,m,k;cin>>n>>m>>k;
       vector<pair<ll,int>> a(n);
       for(int i=0;i<n;i++) {
        cin>>a[i].first;
        a[i].second=i;
       }
       sort(all(a));
       auto [maxP,maxPos]=a[(k+m-1)/m - 1];
       //take roof(k/m) minm days
       vector<pair<int,ll>> a_pick;
       for(int i=0;i<(k+m-1)/m;i++){
        a_pick.push_back({a[i].second,a[i].first});
       }
       sort(all(a_pick)); // get in increasing order of days
       ll ans=0ll,got=0ll;
       for(auto &[pos,p]:a_pick){
        // cout<<p<<" ";
        if(pos==maxPos && k%m!=0){
            ans+=(k%m)*(p+got);
            got+=k%m;
        }
        else{
            ans+=m*(p+got);
            got+=m;
        }
        // cout<<got<<" ";
       }
       cout<<ans<<"\n";

    }
    return 0;
}