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
       // prf[i] denotes sum of +ves among a[i],a[i+1]..a[n]
       vector<ll> prf(n+1,0ll);
       for(int i=n-1;i>=0;i--){
        prf[i]=prf[i+1]+max(0,a[i]);
       }
       ll ans=0ll;
       for(int i=0;i<n;i++){
        ans=max(ans,(i%2==0?a[i]:0)+prf[i+1]);
       }
       cout<<ans<<"\n";
    }
    return 0;
}