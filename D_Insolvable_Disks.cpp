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
       vector<ll> x(n+1);
       for(int i=1;i<=n;i++) cin>>x[i];
       ll l=0,r=1e9+1,altSum=0ll,ans=0ll,sign=-1;// r1 E (l,r) both l and r exclusive
       // expression for radii of first chain
       // 0< r[i+1]=(-1)^i (r1+sum(dj (-1)^j j from 1 to i)) <= d[i+1]
       for(int i=1;i<=n-1;i++){
        // try adding i+1-th disc to the current chain

        // update for lower bound (>0)
        ll d=x[i+1]-x[i];// d[i]=x[i+1]-x[i]
        if(sign==1) {
            altSum+=d;
            // r1+altSum>0
            l=max(l,-altSum);
        }
        else {
            altSum-=d;
            // -r1-altSum>0 -> r1+altSum<0
            r=min(r,-altSum);
        }

        // update for upper bound(<=d[i+1])
        if(i < n-1) {
            ll dn = x[i+2] - x[i+1];
            if(sign == -1) { 
                l = max(l, -dn - altSum);
            }
            else { 
                r = min(r, dn - altSum);
            }
        }

        sign*=-1;//toggle
        // check for validity
        if(0<=l && l<r){
            ans++;
        }
        // reset if chain becomes invalid
        else{
            l=0;
            r=1e9+1;
            altSum=0;
            sign=-1;
        }
       }
       cout<<ans<<'\n';
    }
    return 0;
}