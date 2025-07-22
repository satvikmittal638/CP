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
       vector<ll> b(n);for(auto &i:b) cin>>i;
       vector<ll> divs;
       auto updateDivs=[&](ll x,ll y){
        ll cand=1ll;
        for(ll i=1;i*i<=x;i++){
            if(x%i==0 && y%i==0){
                
            }
        }
       }
       for(int i=0;i<n-1;i++){
        if()
       }
    }
    return 0;
}