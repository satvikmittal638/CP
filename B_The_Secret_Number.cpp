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
       ll z=1e18;
       vector<ll> ans;
       for(int i=0;i<20 && z>=10;i++){
        if(n%(z+1)==0){
            ans.push_back(n/(z+1));
        }
        z/=10;
       }
       cout<<ans.size()<<"\n";
       for(auto e:ans) cout<<e<<" ";
       cout<<"\n";
    }
    return 0;
}