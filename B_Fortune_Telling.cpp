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
       ll n,x,y,sum=0ll;cin>>n>>x>>y;
       for(int i=1;i<=n;i++){
        ll a;cin>>a;
        sum+=a;
       }
        auto hasSameParity=[](ll a,ll b){
            return (a%2==0 && b%2==0)||
                    (a%2!=0 && b%2!=0);
        };

        // input and output must have same parity
        bool aliceWin=0;
       if(sum%2==0){
        if(hasSameParity(x,y)){
            aliceWin=1;
        }
       }else{
        if(!hasSameParity(x,y)){
            aliceWin=1;
        }
       }
       cout<<(aliceWin?"Alice":"Bob")<<"\n";

    }
    return 0;
}