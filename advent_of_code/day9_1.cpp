#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    ll a, b;
    char c; // to read comma
    vector<pair<ll,ll>> crds;
    while (cin >> a >> c >> b) {
        crds.emplace_back(a,b);
    }
    int n=crds.size();
    ll ans=0ll;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans=max(ans,(abs(crds[i].first-crds[j].first)+1)*(abs(crds[i].second-crds[j].second)+1));
        }
    }
    cout<<ans;
    return 0;
}