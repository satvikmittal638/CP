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
       vector<char> opl(n+1),opr(n+1);
       vector<ll> al(n+1),ar(n+1);
       for(int i=1;i<=n;i++){
        cin>>opl[i]>>al[i]>>opr[i]>>ar[i];
       }
       
       // Compute the future chain of maximal multiplication
       //dp_l[i] is maxm no. of ppl a single person can become if they are in the left lane just before gate i
       
       vector<ll> dp_l(n+2,0ll),dp_r(n+2,0ll);
       dp_l[n+1]=dp_r[n+1]=1ll;//base:no gate after n, so no change
       for(int i=n;i>=1;i--){
        if(opl[i]=='+'){
            dp_l[i]=dp_l[i+1];
        }
        if(opr[i]=='+'){
            dp_r[i]=dp_r[i+1];
        }
        if(opl[i]=='x'){
            dp_l[i]=dp_l[i+1]+(al[i]-1)*max(dp_l[i+1],dp_r[i+1]);
        }
        if(opr[i]=='x'){
            dp_r[i]=dp_r[i+1]+(ar[i]-1)*max(dp_l[i+1],dp_r[i+1]);
        }
       }
       ll ans=dp_l[1]+dp_r[1]; // initially 1 person in each lane
       for(int i=1;i<=n;i++){
        if(opl[i]=='+'){
            ans+=al[i]*max(dp_l[i+1],dp_r[i+1]);
        }

        if(opr[i]=='+'){
            ans+=ar[i]*max(dp_l[i+1],dp_r[i+1]);
        }
       }
       cout<<ans<<"\n";
    }
    return 0;
}