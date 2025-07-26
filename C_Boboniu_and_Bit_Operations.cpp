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
    vector<int> a(n),b(m);
    for(auto &i:a) cin>>i;
    for(auto &i:b) cin>>i;
    ll ans=0;
    for(int i=0;i<n;i++){
        int mn=INT_MAX;
        for(int j=0;j<m;j++){
            mn=min(mn,a[i]&b[j]);
        }
        ans|=mn;
    }
    cout<<ans;
    return 0;
}