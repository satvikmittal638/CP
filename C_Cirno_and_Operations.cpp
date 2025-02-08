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
       vector<ll> a(n);for(auto &i:a) cin>>i;
       ll ans=LLONG_MIN;
       for(int i=1;i<=n;i++){
        ll curSum=accumulate(all(a),0ll);
        if(i==1) ans=max(ans,curSum); // if u can't perform reversal
        else ans=max(ans,abs(curSum));
        for(int i=0;i<a.size()-1;i++){
            a[i]=a[i+1]-a[i];
        }
        a.pop_back();
       }
       cout<<ans<<"\n";
    }
    return 0;
}