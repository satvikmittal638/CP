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
       ll n,s;cin>>n>>s;
       auto sumOfDig=[](ll n){
        ll sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
       };
       ll ans=0ll;
       ll pos=1ll;
       while(sumOfDig(n)>s){
        ans+=pos*(10-(n%10)); // make last digit 0
        n/=10;
        n+=1;
        pos*=10;
       }
       cout<<ans<<"\n";
    }
    return 0;
}