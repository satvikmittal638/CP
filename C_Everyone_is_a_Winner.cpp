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
       ll n;cin>>n;
       set<ll> ans;
       for(int x=0;x*x<n;x++){
        ans.insert(x);
       }
       for(int k=1;k*k<=n;k++){
        ans.insert(n/k);
       }
       cout<<ans.size()<<"\n";
       for(auto e:ans) cout<<e<<" ";
       cout<<"\n";
    }
    return 0;
}