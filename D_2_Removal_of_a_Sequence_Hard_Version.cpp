#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll MAX=1e12;
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       ll x,y,k;cin>>x>>y>>k;
       if(y==1){
        cout<<"-1\n";
        continue;
       }
       ll ans=k;
       // perform x-opn in reverse
       while(x>0){
        ll gaps=(ans-1)/(y-1);
        if(gaps==0) break; // no gaps left, so we reached our ans already
        // now lets move in blocks, gaps remain stagnant at its value and changes only when we hit the upper bound +1 = (v+1)*(y-1) + 1
        ll where_gaps_change=(gaps+1)*(y-1)+1;
        ll dist=where_gaps_change-ans;
        ll steps=(dist+gaps-1)/gaps;
        steps=min(steps,x);
        ans+=steps*gaps;
        x-=steps;
        // no valid sequence exists
        if(ans>MAX){
            ans=-1;
            break;
        }
       }
       cout<<ans<<'\n';
    }
    return 0;
}