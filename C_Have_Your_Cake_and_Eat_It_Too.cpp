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
       ll n;cin>>n;
       vector<vector<ll>> cost(3,vector<ll>(n,0ll));
       for(auto &i:cost[0]) cin>>i;
       for(auto &i:cost[1]) cin>>i;
       for(auto &i:cost[2]) cin>>i;
       vector<vector<ll>> p(3,vector<ll>(n,0ll));
       p[0][0]=cost[0][0];
       p[1][0]=cost[1][0];
       p[2][0]=cost[2][0];
       for(ll i=1;i<n;i++){
        p[0][i]=p[0][i-1]+cost[0][i];
        p[1][i]=p[1][i-1]+cost[1][i];
        p[2][i]=p[2][i-1]+cost[2][i];
       }
       ll need=(p[0][n-1]+2)/3;
       vector<ll> t={0,1,2};
       vector<pair<ll,ll>> ans(3);
       bool found=0;
       for(ll i=0;i<6;i++){
        ll z1=0,z2;
        while(z1<n && p[t[0]][z1]<need){
            z1++;
        }
        if(z1>=n-2) {
            next_permutation(all(t));
            continue;
        }
        z2=z1+1;
        while(z2<n && p[t[1]][z2]-p[t[1]][z1]<need){
            z2++;
        }
        if(z2>=n-1 || p[t[2]][n-1]-p[t[2]][z2]<need) {
            next_permutation(all(t));
            continue;
        }
        ans[t[0]]={1,z1+1};
        ans[t[1]]={z1+2,z2+1};
        ans[t[2]]={z2+2,n};
        found=1;
       }
       if(!found) {
        cout<<"-1\n";
        continue;
       }
       auto [la,ra]=ans[0];
       auto [lb,rb]=ans[1];
       auto [lc,rc]=ans[2];
       cout<<la<<" "<<ra<<" "<<lb<<" "<<rb<<" "<<lc<<" "<<rc<<"\n"; 
    }
    return 0;
}