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
       vector<int> b(n);for(auto &i:b) cin>>i;
       ll cntNon0=0;
       ll sum=0ll;
       for(int i=0;i<n;i++){
        cntNon0+=b[i]!=0;
        sum+=b[i];
       }
       ll ans=min(accumulate(all(b),0ll)-n+1,cntNon0);
       // can't perform a single operation on whole stretch of non-0 no's
       cout<<ans<<'\n';
    }
    return 0;
}