#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    ll tt;cin>>tt;
    while(tt--){
       ll n,q;cin>>n>>q;
       vector<ll> a(n);
       for(ll i=0;i<n;i++) {
        cin>>a[i];a[i]--;
       }
       
       // emulate rounds till n comes at position 1(i.e. do it for n times)
       map<ll,vector<ll>> mp;//person->vector of rounds won by him in the first n rounds
       
       //base case-1st round
       ll winner=0;
       if(a[0]<a[1]) {
        winner=1;
       }
       mp[winner].push_back(1);
       // play subsequent rounds
       for(ll i=2;i<n;i++){
        if(a[winner]<a[i]) winner=i;
        mp[winner].push_back(i);
       }
       // now n is at the start, so all matches are won by it
       while(q--){
        ll i,k;cin>>i>>k;i--;
        ll ans;
        auto it=upper_bound(all(mp[i]),k);
        ans=it-mp[i].begin();
        
        // strongest person wins the subsequent rounds
        if(a[i]==n-1 && k>=n){
            ans+=k-(n-1); 
        }
        cout<<ans<<"\n";
       }
    }
    return 0;
}