#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n;cin>>n;
    map<int,ll> mp; // b[i]-i --> sum
    for(int i=1;i<=n;i++){
        int b;cin>>b;
        mp[b-i]+=0ll+b;
    }

    ll ans=0ll;
    for(auto &p:mp){
        ans=max(ans,p.second);
    }
    cout<<ans;
    return 0;
}