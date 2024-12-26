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
       vector<int> a(n+1);
       for(int i=1;i<=n;i++){
        cin>>a[i];
       }
       int l=1,r=1,ans=0;
       for(int i=2;i<=n;i++){
        if(a[i-1]/a[i]<=1){
            r=i;
        }
        // condition violated,make a break and start again
        else {
            ans+=max((r-l+1)-(k+1)+1,0); 
            l=i;
        }
        // cout<<l<<" "<<r<<" ";
       }
       // explicitly do the last update
       if(r==n){
            ans+=max((r-l+1)-(k+1)+1,0); 
       }
       cout<<ans<<"\n";
    }
    return 0;
}