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
       vector<ll> odds,evens;
       for(int i=0;i<n;i++){
        ll a;cin>>a;
        if(a%2==0) evens.push_back(a);
        else odds.push_back(a);
       }
       if(odds.size()==0){
        cout<<"0\n";
        continue;
       }
       ll ans=0ll;
       sort(all(odds));
       ans+=accumulate(all(evens),0ll);
       ans+=odds.back(); // maxm odd taken
       odds.pop_back();
       reverse(all(odds));
       // take first floor(k/2) odds,k=odds.size
       for(int i=0;i<(odds.size())/2;i++){
        ans+=odds[i];
       }
       cout<<ans<<'\n';

    
    }
    return 0;
}