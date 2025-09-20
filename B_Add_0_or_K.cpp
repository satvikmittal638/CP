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
       ll n,k;cin>>n>>k;
       vector<ll> a(n);for(auto &i:a) {
        cin>>i;
        i+=k*(i%(k+1));
       }
       for(auto e:a) cout<<e<<" ";
       cout<<'\n';
    }
    return 0;
}