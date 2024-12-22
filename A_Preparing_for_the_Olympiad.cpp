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
       vector<int> a(n),b(n);
       for(auto &i:a) cin>>i;
       for(auto &i:b) cin>>i;
        int ans=0;
       for(int i=0;i<n-1;i++){
        ans+=max(a[i]-b[i+1],0);
       }
       ans+=a[n-1];
       cout<<ans<<"\n";
    }
    return 0;
}