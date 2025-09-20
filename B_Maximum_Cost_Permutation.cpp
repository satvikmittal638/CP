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
       vector<int> p(n+1);
       int l=n+10,r=-1;
       vector<bool> used(n+1,0);
       for(int i=1;i<=n;i++) {
        cin>>p[i];
        used[p[i]]=1;
       }
       int mn=-1,mx=n+10;
       for(int i=1;i<=n;i++){
        if(!used[i]) {mn=i;break;}
       }
       for(int i=n;i>=1;i--){
        if(!used[i]) {mx=i;break;}
       }
       for(int i=1;i<=n;i++){
        if(p[i]==0){
            p[i]=mx;break;
        }
       }
       for(int i=n;i>=1;i--){
        if(p[i]==0){
            p[i]=mn;break;
        }
       }
       for(int i=1;i<=n;i++){
           // i and p[i] must be swapped
            if(p[i]!=0 && p[i]!=i){
                l=min(l,min(i,p[i]));
                r=max(r,max(i,p[i]));
            }
       }
       int ans=0;
       if(l<=n && r>=1){
        ans=r-l+1;
       }
       cout<<ans<<'\n';
       
    }
    return 0;
}