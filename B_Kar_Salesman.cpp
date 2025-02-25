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
       int n,x;cin>>n>>x;
       vector<ll> a(n);for(auto &i:a) cin>>i;
       auto isSafe=[&](ll k){
        ll lvlInd=1ll,lvlVal=0ll;
        for(int i=0;i<n;i++){
            // if(a[i]>k) return false;
            if(lvlVal+a[i]<=k){
                lvlVal+=a[i];
            }
            else{
                lvlVal=a[i]-(k-lvlVal);
                lvlInd++;
            }
        }
        return lvlInd<=x;
       };
       ll lo=*max_element(all(a)),hi=accumulate(all(a),0ll),ans;
       while(lo<=hi){
        ll mid=(lo+hi)/2;
        if(isSafe(mid)){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
       }
       cout<<ans<<"\n";

    }
    return 0;
}