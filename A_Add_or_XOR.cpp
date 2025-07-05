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
       ll a,b,x,y;cin>>a>>b>>x>>y;
       if((a-b)==1 && a%2!=0){
        cout<<y<<"\n";
        continue;
       }
       if(b-a<0){
        cout<<"-1\n";
        continue;
       }
       ll ans=0ll;
       for(int i=a;i<b;i++){
        if(i%2==0){
            ans+=min(x,y);
        }
        else{
            ans+=x;
        }
       }
       cout<<ans<<"\n";
    }
    return 0;
}