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
        ll a,b;cin>>a>>b;
        ll ans=30;
        if(a<b) swap(a,b);
        // a>=b
        while(ans>=0){
            ll od=0,ev=0;
            for(int i=0;i<=ans;i+=2){
                ev|=(1<<i);
            }
            for(int i=1;i<=ans;i+=2){
                od|=(1<<i);
            }
            if(ev<od) swap(ev,od);
            // ev>=od
            // found ans
            if(ev<=a && od<=b) break;
            else ans--;
        }
        cout<<ans+1<<'\n';
    }
    return 0;
}