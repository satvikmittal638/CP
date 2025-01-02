#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n,k;cin>>n>>k;
    vector<pair<int,ll>> segSums;
    vector<ll> pref(n+1,0ll);
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        pref[i]=pref[i-1]+x;
    }
    for(int i=1;i<=n-k+1;i++){
        segSums.emplace_back(i,pref[i+k-1]-pref[i-1]);
    }
    
    return 0;
}