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
       vector<int>a(n),pmax(n);for(auto &i:a) cin>>i;
       pmax[0]=a[0];
       for(int i=1;i<n;i++){
        pmax[i]=max(pmax[i-1],a[i]);
       }
       int ans=0;
       for(int i=n-1;i>=1;i--){
        if(pmax[i-1]>a[i]) ans++;
       }
       cout<<ans<<'\n';
    }
    return 0;
}