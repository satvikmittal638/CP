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
       ll curEveSum=0ll,curOddSum=0ll,maxEl=INT_MIN,ans;
       for(int i=1;i<=n;i++){
        ll c;cin>>c;
        if(i%2==0){
            if(c>=0) curEveSum+=c;
        }else{
            if(c>=0) curOddSum+=c;
        }
        maxEl=max(maxEl,c);
       }
       ans=max(curEveSum,curOddSum);
        if(maxEl<0) ans=maxEl;
        cout<<ans<<"\n";
    }
    return 0;
}