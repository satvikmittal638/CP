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
       if(n==2){
        cout<<(max(a[0]-a[1],0))<<'\n';
        continue;
       }
       ll ans=0ll;
       for(int i=1;i<n;i+=2){
        int op=max(a[i-1]+(i<n-1?a[i+1]:0)-a[i],0);
        ans+=op;
        if(i<n-1 && a[i+1]>op) a[i+1]-=op;
        else {
            if(i<n-1) {
                a[i+1]=0;
                op-=a[i+1];
            }
            a[i-1]-=op;
        }
       }
       cout<<ans<<'\n';
    }
    return 0;
}