#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    ll MAX=1e6;
    vector<vector<ll>> pref(2001,vector<ll>(2001,0ll));
    vector<ll> ans(2*MAX+7,0ll);
    ll cur=1;
    // equation of a diagonal is r+c=k, where c increases and r decreases for a (1,2,3.,4) in order traversal
    for(int k=1;k<=2000;k++){
        for(int c=1;c<k;c++){
            int r=k-c;
            pref[r][c]=pref[r][c-1]+pref[r-1][c]-pref[r-1][c-1]+(cur*cur);
            ans[cur]=pref[r][c];
            cur++;
        }
    }

    int tt;cin>>tt;
    while(tt--){
       ll n;cin>>n;
       cout<<ans[n]<<'\n';
    }
    return 0;
}