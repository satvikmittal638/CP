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
       vector<int> a(n);for(auto &i:a) cin>>i;
       ll ans=0ll;
       for(int l=0;l<n;l++){
        for(int r=l;r<n;r++){
            ll s=accumulate(a.begin()+l,a.begin()+r+1,0ll);
            ans=max(ans,s/(r-l+1));
        }
       }
       cout<<ans<<'\n';
    }
    return 0;
}