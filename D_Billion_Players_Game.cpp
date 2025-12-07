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
       ll n,l,r;cin>>n>>l>>r;
       vector<ll> a(n);for(auto &i:a) cin>>i;
       sort(all(a));
       //find median of the array
       ll med=a[n/2];
       if(med<l) med=l;
       else if(med>r) med=r;
       ll ans=0ll;
       for(int i=0;i<n;i++) ans+=abs(a[i]-med);
       cout<<ans<<'\n';
    }
    return 0;
}