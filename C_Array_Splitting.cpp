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
    vector<ll> a(n);for(auto &i:a) cin>>i;
    vector<ll> diff;
    for(int i=1;i<n;i++){
        diff.push_back(a[i]-a[i-1]);
    }
    sort(rall(diff));
    ll ans=a[n-1]-a[0];
    for(int i=0;i<k-1;i++){
        ans-=diff[i];
    }
    cout<<ans;
    return 0;
}