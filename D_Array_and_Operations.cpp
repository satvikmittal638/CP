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
       int n,k;cin>>n>>k;
       vector<int> a(n);for(auto &i:a) cin>>i;
       sort(all(a));
       int i=0,j=n-1;
       ll ans=0ll;
       for(int i=n-2*k;i<n-k    ;i++){
        ans+=a[i]/a[i+k];
       }
       ans+=accumulate(a.begin(),a.end()-2*k,0ll);
       cout<<ans<<"\n";
    }
    return 0;
}