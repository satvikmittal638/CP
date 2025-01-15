#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n,m;cin>>n>>m;
    vector<int> a(n);
    for(auto &i:a) cin>>i;
    sort(all(a));
    vector<ll> pref(n,0ll);
    for(int i=0;i<n;i++){
        pref[i]+=a[i];
        if(i>0) pref[i]+=pref[i-1];
    }
    vector<ll> ans(n,0ll);
    for(int k=0;k<n;k++){
        ans[k]=pref[k]+(k>=m?ans[k-m]:0ll);
    }
    for(auto e:ans) cout<<e<<" ";
    return 0;
}