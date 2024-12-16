#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       long long k,l1,r1,l2,r2;cin>>k>>l1>>r1>>l2>>r2;
       long long kpown=1,ans=0ll;
       // Start kpown from the nearest power of k >= l2/r1
       /*
      since xk^n E [l2,r2], maximize x(i.e put it to r1) to minimize k^n and get its lower bound as l2/r1
       similarly minimize x(put it as l1) to get maximize k^n and get its upper bound as r2/l1
       */ 
        while (kpown < l2/r1) {
            kpown *= k;
        }
        while(kpown<=r2/l1){
            // bounds of x
            long long lo=max(l1,(l2+kpown-1)/kpown),hi=min(r1,r2/kpown);
            if(lo<=hi){
                ans+=hi-lo+1;
            }
            kpown*=k;
        }
        cout<<ans<<"\n";
    }
    return 0;
}