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
       int n,m;cin>>n>>m;
       vector<int> a(n),b(m);
       for(auto &i:a) cin>>i;
       for(auto &i:b) cin>>i;
        
       bool ok=1;
       a[0]=min(a[0],b[0]-a[0]);
       for(int i=1;i<n;i++){
        int mx=max(a[i],b[0]-a[i]),mn=min(a[i],b[0]-a[i]);
        if(a[i-1]<=mn) a[i]=mn;
        else if(a[i-1]<=mx) a[i]=mx;
        else {
            ok=0;break;
        }
       }
       cout<<(ok?"YES":"NO")<<"\n";
    }
    return 0;
}