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
    vector<ll> a(n),b(m);
    for(auto &i:a) cin>>i;
    for(auto &i:b) cin>>i;
    ll h2=0ll;
    sort(all(a));
    for(int i=1;i<n;i++){
        h2=gcd(h2,a[i]-a[i-1]);
    }
    for(int j=0;j<m;j++){
        cout<<gcd(a[0]+b[j],h2)<<" ";
    }
    return 0;
}