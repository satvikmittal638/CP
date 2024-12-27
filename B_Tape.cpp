#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n,m,k;cin>>n>>m>>k;
    vector<int> b(n);for(auto &i:b) cin>>i;
    ll ans=n; // first cover each broken segment with a tape of length 1
    vector<int> tapes;
    for(int i=0;i<n-1;i++){
        tapes.emplace_back(b[i+1]-b[i]-1); // L(s+1,e-1)=e-s-1
    }
    sort(all(tapes));
    // now cover shortest n-k undamaged segments
    for(int i=0;i<min((int)tapes.size(),n-k);i++){
        ans+=tapes[i];
    }
    cout<<ans;
    return 0;
}