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
       map<pair<int,int>,ll> cnt23,cnt13,cnt12;
       map<pair<int,pair<int,int>>,ll> cnt123;
       for(int i=0;i<n-2;i++){
        cnt123[{a[i],{a[i+1],a[i+2]}}]++;
        cnt12[{a[i],a[i+1]}]++;
        cnt23[{a[i+1],a[i+2]}]++;
        cnt13[{a[i],a[i+2]}]++;
        }
        ll ans=0ll;
        // count beautiful pairs
        for(auto &[p2,cnt]:cnt12){
            ans+=cnt*(cnt-1)/2;
        }
        for(auto &[p2,cnt]:cnt23){
            ans+=cnt*(cnt-1)/2;
        }
        for(auto &[p2,cnt]:cnt13){
            ans+=cnt*(cnt-1)/2;
        }
        // remove rpted counts
        for(auto &[p3,cnt]:cnt123){
            ans-=3*cnt*(cnt-1)/2;
        }
        cout<<ans<<"\n";
    }
    return 0;
}