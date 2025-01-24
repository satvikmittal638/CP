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
       int cntO=0,cntE=0;
       for(int i=0;i<n;i++){
        int a;cin>>a;
        if(a%2==0) cntE++;
        else cntO++;
       }
       int ans;
       if(cntE>=1){
        ans=cntO+1;
       }
       else{
        ans=cntO-1;
       }
       cout<<ans<<"\n";
    }
    return 0;
}