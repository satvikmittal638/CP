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
       sort(all(b));
       a[0]=min(a[0],b[0]-a[0]);
       bool ok=1;
       for(int i=1;i<n;i++){
        auto it=lower_bound(all(b),a[i]+a[i-1]);
        if(it!=b.end()){
            int minB=*it;
            int mx=max(a[i],minB-a[i]),mn=min(a[i],minB-a[i]);
            if(a[i-1]<=mn) a[i]=mn;
            else if(a[i-1]<=mx) a[i]=mx;
            else {
                ok=0;break;
            }
        }
        else{
            if(a[i-1]>a[i]){
                ok=0;break;
            }
        }
       }
       cout<<(ok?"YES":"NO")<<"\n";
    }
    return 0;
}