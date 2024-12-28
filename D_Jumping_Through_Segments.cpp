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
       vector<ll> l(n),r(n);
       for(int i=0;i<n;i++) cin>>l[i]>>r[i];
       auto check=[&](int k){
        ll myl=0,myr=0;
        for(int i=0;i<n;i++){
            // expand the segment
            myl-=k;myr+=k; 
            myl=max(myl,l[i]);
            myr=min(myr,r[i]);
            // check the intersection with next segment
            if(myl>myr) return 0;
        }
        return 1;
       };
       int lo=0,hi=*max_element(all(r));
       while(lo<hi){
        int mid=(lo+hi)/2;
        if(check(mid)){
            hi=mid;
        }
        else{
            lo=mid+1;
        }
       }
       cout<<lo<<"\n";
    // using inbuilt functions
// int ans = *ranges::partition_point(ranges::iota_view(0, int(1E9) + 1),
//         check);    
//         cout<<ans<<"\n";
    }
    return 0;
}